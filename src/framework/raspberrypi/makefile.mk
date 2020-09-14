all: pal wrapper

wholepal: gpio-rpi.o spic-rpi.o timer-rpi.o TLE94112-pal-rpi.o
	g++ -o wholepal gpio-rpi.o spic-rpi.o timer-rpi.o TLE94112-pal-rpi.o

pal: 
	g++ -c gpio-rpi.cpp -lwiringPi
	g++ -c spic-rpi.cpp -lwiringPiSPI
	g++ -c timer-rpi.cpp -lwiringPi
	g++ -c TLE94112-pal-rpi.cpp -lwiringPi

wrapper: 

clean: 
	rm -f pal 
	rm -f wrapper 
	rm -f *.o
