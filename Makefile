CC := gcc
ALLEGRO_LIB := -lallegro #INCLUIR ACA TODO ALLEGRO!!
CFLAGS := -Wall 
OBJ_FILES := frogger.o game_logic.o objects.o frogger_state.o input.o render.o
EXECUTABLE_NAME := frogger

all: pc #just an alias

pc: ${OBJ_FILES}
	${CC}  ${OBJ_FILES} -o ${EXECUTABLE_NAME} ${ALLEGRO_LIB} ${CFLAGS}

frogger.o: frogger.c frogger_state.h game_logic.h
	${CC}  -o frogger.o -c frogger.c ${CFLAGS}

frogger_state.o: frogger_state.c frogger_state.h objects.h
	${CC} -o frogger_state.o -c frogger_state.c ${CFLAGS}

game_logic.o: game_logic.c game_logic.h frogger_state.h objects.h input.h render.h
	${CC} -o game_logic.o -c game_logic.c ${CFLAGS} 

objects.o: objects.c objects.h
	${CC} -o objects.o -c objects.c ${CFLAGS}

input.o: input_stub.c input.h #CURRENTLY A STUB!
	${CC} -o input.o -c input_stub.c ${CFLAGS}

render.o: render_stub.c render.h frogger_state.h #CURRENTLY A STUB
	${CC} -o render.o -c render_stub.c ${CFLAGS}

	
clean:
	rm -f ${OBJ_FILES} ${EXECUTABLE_NAME}