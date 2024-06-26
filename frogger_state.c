#include "frogger_state.h"
#include <stdio.h>
#include <stdlib.h>

/*
    @BRIEF: Here the shared objects live 
*/

cell_t    state_matrix[CELLS_Y_MAX][CELLS_X_MAX];
object_t  current_objects[MAX_OBJECTS];
object_t ranita;
lane_t lanes[LANES_COUNT];

