# -*- coding: utf-8 -*-
import os
import sys
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

# Convert distutils Windows platform specifiers to CMake -A arguments
PLAT_TO_CMAKE = {
    "win32": "Win32",
    "win-amd64": "x64",
    "win-arm32": "ARM",
    "win-arm64": "ARM64",
}

class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=""):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)

class CMakeBuild(build_ext):
    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))

        if not extdir.endswith(os.path.sep):
            extdir += os.path.sep

        cfg = "Debug" if self.debug else "Release"

        cmake_generator = os.environ.get("CMAKE_GENERATOR", "")

        # Ensure necessary environment variables are set
        cmake_prefix_path = subprocess.check_output(
            [sys.executable, "-m", "pybind11", "--cmakedir"]
        ).strip().decode()
        os.environ["CMAKE_PREFIX_PATH"] = cmake_prefix_path

        cmake_args = [
            "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={}".format(extdir),
            "-DPYTHON_EXECUTABLE={}".format(sys.executable),
            "-DEXAMPLE_VERSION_INFO={}".format(self.distribution.get_version()),
            "-DCMAKE_BUILD_TYPE={}".format(cfg),
        ]

        build_args = []

        if self.compiler.compiler_type != "msvc":
            if not cmake_generator:
                cmake_args += ["-GNinja"]
        else:
            single_config = any(x in cmake_generator for x in {"NMake", "Ninja"})
            contains_arch = any(x in cmake_generator for x in {"ARM", "Win64"})

            if not single_config and not contains_arch:
                cmake_args += ["-A", PLAT_TO_CMAKE[self.plat_name]]

            if not single_config:
                cmake_args += [
                    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}".format(cfg.upper(), extdir)
                ]
                build_args += ["--config", cfg]

        if "CMAKE_BUILD_PARALLEL_LEVEL" not in os.environ:
            if hasattr(self, "parallel") and self.parallel:
                build_args += ["-j{}".format(self.parallel)]

        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        subprocess.check_call(["cmake", ext.sourcedir] + cmake_args, cwd=self.build_temp)
        subprocess.check_call(
            ["cmake", "--build", "."] + build_args,
            cwd=self.build_temp
        )

setup(
    name="multi-half-bridge",
    version="5.0.1",
    author="Infineon Technologies",
    description="Python Library for Infineon's multi half-bridge IC drivers",
    long_description="Python library for Infineons multi half-bridge IC drivers",
    project_urls={
        'Source': 'https://github.com/Infineon/multi-half-bridge',
        'Wiki': 'https://github.com/Infineon/multi-half-bridge/wiki',
        'IC Products Page': 'https://www.infineon.com/cms/de/product/power/motor-control-ics/brushed-dc-motor-driver-ics/multi-half-bridge-ics/'
    },
    ext_modules=[CMakeExtension("multi_half_bridge_py", sourcedir=".")],
    cmdclass={"build_ext": CMakeBuild},
    license='MIT',
    url='https://pypi.org/project/multi-half-bridge/',
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    zip_safe=False,
)
