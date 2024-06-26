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
            if (map[i][j].kind)printf("*");
            else printf("_");
        }
        printf("\n");
    }

    printf("\n\n\n\n");
}