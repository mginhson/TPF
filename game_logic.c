#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Aca existe current_objects[]
extern object_t current_objects[MAX_OBJECTS]; //REDUNDANTE!!!

static void updateObjects(void);
static void updateMatrix(void);

void nextLogicTick(void)
{
    updateObjects();
    updateMatrix();
}


static void updateMatrix(void)
{

}


static void updateObjects(void)
{
    uint32_t i;
    for(i=0; i < sizeof(current_objects)/sizeof(*current_objects); ++i)
    {
        if (current_objects[i].kind == none) //no hay nada en este slot
        {
            continue;
        }
        
    }
}