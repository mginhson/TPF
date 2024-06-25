#include "frogger_state.h"
#include <stdio.h>
#include <stdlib.h>

void access(void){puts("ranita");};
cell_t    state_matrix[MAP_Y_MAX][MAP_X_MAX];
object_t  current_objects[MAX_OBJECTS];
/*
    @BRIEF: Despues de que se hayan actualizado los objetos, 
*/

