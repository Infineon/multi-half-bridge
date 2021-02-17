
The source folder structure is organized according to the described architecture in the [Library Architecture](Library-Architecture) section: 

```
root
+-- docs/
+-- src/
    +-- config/
    +-- corelib/
    +-- framework/
        +-- fmwkA/
            +-- pal/
            +-- wrapper/
            +-- ...
        +-- fwmkB/
            +-- pal/
            +-- wrapper/
            +-- ...
        +-- ...
    +-- pal/
    +-- ...
+-- test
+-- ...
```

Additional folders for utilities and metadata files (i.e. makefiles, manifests, git files, LICENSE...) used by the software toolchain and development environment can (and will) as well be found in these folders together with the .hpp, .h, .cpp and .c sources. 

## :warning: Exceptions

Currently exceptions to this structure are found for backward compatibility reasons. Particularly, in order to keep the repository as an Arduino library, which requires to comply with the [Arduino Library Specification 1.5](https://arduino.github.io/arduino-cli/library-specification/).

Future revision will relocate these files more consistent with the proposed architecture, and consider separate release repositories for specific framework toolchain requirements. 