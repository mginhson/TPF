#include "frogger_state.h"
#include <stdio.h>
#include <stdlib.h>

/*
    @BRIEF: Here the shared objects live 
*/

cell_t    state_matrix[CELLS_Y_MAX][CELLS_X_MAX];
object_t  current_objects[MAX_OBJECTS];
frog_t ranita;
lane_t lanes[LANES_COUNT];
logic_cell_t map[CELLS_Y_MAX][CELLS_X_MAX];

const char * background_t_string_names[]={"water","road","grass","finish_line"};