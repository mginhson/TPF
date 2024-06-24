CC := gcc
ALLEGRO_LIB := -lallegro #INCLUIR ACA TODO ALLEGRO!!
CFLAGS := -Wall -Wextra
OBJ_FILES := frogger.o
EXECUTABLE_NAME := frogger

pc: ${OBJ_FILES}
	${CC}  ${OBJ_FILES} -o ${EXECUTABLE_NAME} ${ALLEGRO_LIB} ${CFLAGS}

frogger.o: frogger.c 
	${CC}  -c frogger.c ${CFLAGS}

clean:
	rm -f ${OBJ_FILES} ${EXECUTABLE_NAME}