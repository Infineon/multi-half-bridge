CPPFLAGS = -DTLE94112_FRAMEWORK=TLE94112_FRMWK_RPI
BUILDPATH = ../../../build

.PHONY: all corelib pal wrapper examples/basicTest examples/control2Motors examples/rampSpeedTest examples/controlwith2HATs

all: examples/basicTest

corelib:
	mkdir -p $(BUILDPATH)
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112.o ../../corelib/tle94112.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112-motor.o ../../corelib/tle94112-motor.cpp

pal: corelib
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/gpio-rpi.o pal/gpio-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/spic-rpi.o pal/spic-rpi.cpp
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/timer-rpi.o pal/timer-rpi.cpp

wrapper: pal
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112-rpi.o wrapper/tle94112-rpi.cpp

examples/basicTest: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/basicTest.o examples/basicTest.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/basicTest $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/control2Motors: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/control2Motors.o examples/control2Motors.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/control2Motors $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/rampSpeedTest: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/rampSpeedTest.o examples/rampSpeedTest.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/rampSpeedTest $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/controlwith2HATs: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/controlwith2HATs.o examples/controlwith2HATs.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/controlwith2HATs $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/errorDiagnosis: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/errorDiagnosis.o examples/errorDiagnosis.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/errorDiagnosis $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835
clean:
	rm -f $(BUILDPATH)/*