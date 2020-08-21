menutest:main.o menu.o scrolling.o collision.o enigf.o
	gcc   main.o menu.o scrolling.o collision.o enigf.o -o menutest -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm
main.o:main.c
	gcc -c main.c -g

menu.o:menu.c
	gcc -c menu.c -g 

scrolling.o:scrolling.c
	gcc -c scrolling.c -g 

collision.o:collision.c
	gcc -c collision.c -g 
enigf.o:enigf.c
	gcc -c enigf.c -g			

