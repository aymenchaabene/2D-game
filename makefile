prog:main.o enigme.o
	gcc   main.o enigme.o -o enigme -lSDL -lSDL_image
main.o:main.c
	gcc -c main.c

enigme.o:enigme.c
	gcc -c enigme.c
