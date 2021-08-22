LIBS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_gfx
INC = -Iinclude -Iinclude/backends/sdl2
OPT = -Wall -pedantic --std=c98

bin/test: obj/backend_sdl.o obj/fejix.o obj/test.o
	gcc $^ -o $@ $(LIBS)

C = gcc -c $< -o $@ $(INC) $(LIBS)

obj/test.o: src/test.c
	$C

obj/fejix.o: src/fejix.c
	$C

obj/backend_sdl.o: src/backends/sdl2/fj_backend.c
	$C