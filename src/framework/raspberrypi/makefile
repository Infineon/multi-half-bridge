CXXFLAGS = -DTLE94112_FRAMEWORK=TLE94112_FRMWK_RPI
BUILDPATH = ../../../build
INCPATH = /usr/local/include
LIBPATH = /usr/local/lib

PCAP := $(shell nm $(LIBPATH)/libbcm2835.a | grep "cap_free" -c)
EXAMPLES := $(basename $(wildcard examples/*.cpp))

.PHONY: default corelib pal wrapper $(EXAMPLES)

default: examples/basicTest

corelib:
	mkdir -p $(BUILDPATH)
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112.o ../../corelib/tle94112.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112-motor.o ../../corelib/tle94112-motor.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112-logger.o ../../corelib/tle94112-logger.cpp

pal: corelib
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/gpio-rpi.o pal/gpio-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/logger-rpi.o pal/logger-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/spic-rpi.o pal/spic-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/timer-rpi.o pal/timer-rpi.cpp

wrapper: pal
	g++ -c $(CXXFLAGS) -o $(BUILDPATH)/tle94112-rpi.o wrapper/tle94112-rpi.cpp

examples/$(EXAMPLES): wrapper
	g++ -c $(CXXFLAGS) -o $(BUILDPATH)/$(@F).o examples/$(@F).cpp -Iwrapper/ -I../../corelib -Ipal
ifeq ($(PCAP), 0)
	g++ $(CXXFLAGS) -o $(BUILDPATH)/$(@F) $(BUILDPATH)/*.o -I$(INCPATH) -L$(LIBPATH) -lbcm2835
else
	g++ $(CXXFLAGS) -o $(BUILDPATH)/$(@F) $(BUILDPATH)/*.o -I$(INCPATH) -L$(LIBPATH) -lbcm2835 -lcap
	sudo setcap cap_sys_rawio+ep $(BUILDPATH)/$(@F)
endif

clean:
	rm -f $(BUILDPATH)/*
