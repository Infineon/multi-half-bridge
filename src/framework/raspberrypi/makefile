CPPFLAGS = -DTLE94112_FRAMEWORK=TLE94112_FRMWK_RPI
BUILDPATH = ../../../build

.PHONY: all corelib pal wrapper examples/basicTest examples/advancedTest examples/multipleMotors examples/multipleControllers examples/errorDiagnosis

all: examples/basicTest

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
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/tle94112-rpi.o wrapper/tle94112-rpi.cpp

examples/basicTest: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/basicTest.o examples/basicTest.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/basicTest $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/advancedTest: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/advancedTest.o examples/advancedTest.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/advancedTest $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/multipleMotors: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/multipleMotors.o examples/multipleMotors.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/multipleMotors $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/multipleControllers: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/multipleControllers.o examples/multipleControllers.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/multipleControllers $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

examples/errorDiagnosis: wrapper
	g++ -c $(CPPFLAGS) -o $(BUILDPATH)/errorDiagnosis.o examples/errorDiagnosis.cpp -Iwrapper/ -I../../corelib -Ipal
	g++ $(CPPFLAGS) -o $(BUILDPATH)/errorDiagnosis $(BUILDPATH)/*.o -I/usr/local/include -L/usr/local/lib -lbcm2835

clean:
	rm -f $(BUILDPATH)/*