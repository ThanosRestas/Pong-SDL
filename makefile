CC=g++
CFLAGS = -O3 -Wall -pedantic -w
OBJECTS = ball.o timer.o button.o paddles.o globals.o
LIBS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 

all:pong

pong:main.cpp $(OBJECTS)
	$(CC) main.cpp $(OBJECTS) $(LIBS) $(CLFAGS) -o pong

globals.o:globals.cpp globals.h
	$(CC) -c globals.cpp $(CFLAGS)

paddles.o:paddles.cpp paddles.h globals.o
	$(CC) -c paddles.cpp $(CFLAGS)

ball.o:ball.cpp ball.h globals.o
	$(CC) -c ball.cpp $(CFLAGS)

timer.o:timer.cpp timer.h globals.o
	$(CC) -c timer.cpp $(CFLAGS)

button.o:button.cpp button.h globals.o
	$(CC) -c button.cpp $(CFLAGS)

clean:
	rm *.o pong
	

	
	
	
	



