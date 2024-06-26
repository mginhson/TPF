#include <stdio.h>
#include <stdlib.h>
#include "render.h"
#include "frogger_state.h"

void render(void)
{
    uint32_t j,i;
    for (i = 0; i < CELLS_Y_MAX; i++)
    {
        for (j =0; j < CELLS_X_MAX; j++)
        {
            if (state_matrix[i][j].frog) printf("R");
            else if (state_matrix[i][j].object) printf("C");
            else printf(" ");
        }
        printf("\n");
    }
}