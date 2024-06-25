#include "frogger_state.h"
#include <stdio.h>
#include <stdlib.h>


cell_t    state_matrix[CELLS_Y_MAX][CELLS_X_MAX];
object_t  current_objects[MAX_OBJECTS];


/*
    @BRIEF: Despues de que se hayan actualizado los objetos, 
*/

