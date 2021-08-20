LIBS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_gfx
INC = -Iinclude -Iinclude/backends/sdl2
OPT = -Wall -pedantic --std=c98

bin/test: obj/backend_sdl.o obj/fejix.o obj/test.o
	gcc $^ -o $@ $(LIBS)

obj/test.o:
	gcc -c src/test.c -o $@ $(INC) $(LIBS)

obj/fejix.o:
	gcc -c src/fejix.c -o $@ $(INC) $(LIBS)

obj/backend_sdl.o:
	gcc -c src/backends/sdl2/fj_backend.c -o $@ $(INC) $(LIBS)