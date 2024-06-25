CC := gcc
ALLEGRO_LIB := -lallegro #INCLUIR ACA TODO ALLEGRO!!
CFLAGS := -Wall -Wextra
OBJ_FILES := frogger.o game_logic.o objects.o frogger_state.o
EXECUTABLE_NAME := frogger

all: pc #just an alias

pc: ${OBJ_FILES}
	${CC}  ${OBJ_FILES} -o ${EXECUTABLE_NAME} ${ALLEGRO_LIB} ${CFLAGS}

frogger.o: frogger.c frogger_state.h 
	${CC}  -o frogger.o -c frogger.c ${CFLAGS}

frogger_state.o: frogger_state.c frogger_state.h game_logic.h objects.h
	${CC} -o frogger_state.o -c frogger_state.c ${CFLAGS}

game_logic.o: game_logic.c game_logic.h objects.h
	${CC} -o game_logic.o -c game_logic.c ${CFLAGS} 

objects.o:
	${CC} -o objects.o -c game_logic.c ${CFLAGS}

clean:
	rm -f ${OBJ_FILES} ${EXECUTABLE_NAME}