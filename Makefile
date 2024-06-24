CC := gcc
ALLEGRO_LIB := -lallegro #INCLUIR ACA TODO ALLEGRO!!
CFLAGS := -Wall -Wextra
OBJ_FILES := frogger.o
EXECUTABLE_NAME := frogger

all: pc #just an alias

pc: ${OBJ_FILES}
	${CC}  ${OBJ_FILES} -o ${EXECUTABLE_NAME} ${ALLEGRO_LIB} ${CFLAGS}

frogger.o: frogger.c 
	${CC}  -o frogger.o -c frogger.c ${CFLAGS}

game_logic.o: game_logic.c game_logic.h
	${CC} -o game_logic.o -c game_logic.c ${CFLAGS} 

clean:
	rm -f ${OBJ_FILES} ${EXECUTABLE_NAME}