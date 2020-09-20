CPPFLAGS = -DTLE94112_FRAMEWORK=TLE94112_FRMWK_RPI
BUILDPATH = ../../../build

all: examples/basicTest

corelib:
	mkdir -p $(BUILDPATH)
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112_util.o ../../corelib/tle94112_util.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/TLE94112.o ../../corelib/TLE94112.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/TLE94112Motor.o ../../corelib/TLE94112Motor.cpp

pal: corelib
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/gpio-rpi.o pal/gpio-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/spic-rpi.o pal/spic-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/timer-rpi.o pal/timer-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/TLE94112-pal-rpi.o pal/TLE94112-pal-rpi.cpp

wrapper: pal
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/TLE94112-platf-rpi.o wrapper/TLE94112-platf-rpi.cpp

examples/basicTest: wrapper
	g++ -c $(CPPFLAGS) -o ../../../build/basicTest.o examples/basicTest.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o ../../../build/basicTest ../../../build/*.o -I/usr/local/include -L/usr/local/lib -lwiringPi

clean:
	rm -f rm -f ../../../build/*