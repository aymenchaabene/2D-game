prog:main.o  vie.o 
	gcc main.o vie.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c 
vie.o:vie.c
	gcc -c vie.c 
clean:
	rm *.o prog
