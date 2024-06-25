
#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"
#include "objects.h"
#include "frogger_state.h"
#include "input.h"

static void moveFrog(void);
static void moveObjects(void);
static void analyzeObjects(void);
static void deleteObject(void);
static int8_t addObject(object_t _obj);
static void analyzeRanita(void);
static void updateLogicMatrix(void);

/*
    @BRIEF: nextLogicTick
    -Move the frog (if needed)
    -Move and/or update the objects 
    -Remove objects that went completely out of bounds
    -Create new objects
    -Analyze wether the frog died or won
    -If the frog won, setup and advance to the next level
    -If it neither died or won, update the logic matrix and handle control over to the render stage
    
*/
void nextLogicTick(void)
{

}

/*
    @BRIEF: moveObjects
        moves the current objects based on their speed (dx,dy) param 
*/
void moveObjects(void)
{
    static const uint32_t  bound = sizeof(current_objects)/sizeof(*current_objects); 
    uint32_t i;
    for(i = 0; i < bound;i++)
    {
        current_objects[i].x += current_objects[i].dx;
        current_objects[i].y += current_objects[i].dy;
    }
    return ;
}

/*
    @BRIEF: analyzeObjects
        if an object went out of bounds, delete it 
*/
void analyzeObjects(void)
{
    static const uint32_t  bound = sizeof(current_objects)/sizeof(*current_objects); 
    uint32_t i;

    for(i = 0; i < bound; ++i)
    {
        //If either is triggered, the object is OOB, and declared none (slot made available for the object creator to take)
        if (current_objects[i].y < 0 || current_objects[i].y-current_objects[i].dist_y > MAP_Y_PIXELS_MAX)
        {
            current_objects[i].kind = none;
        }
        else if (current_objects[i].x > MAP_X_PIXELS_MAX || current_objects[i].x+current_objects[i].dist_y<0)
        {
            current_objects[i].kind = none;
        }
    }
}

/*
    @BRIEF: Copies the new object onto a free slot, returns 0 if succesful, -1 otherwise
*/
int8_t addObject(object_t _obj)
{
    static const uint32_t  bound = sizeof(current_objects)/sizeof(*current_objects); 
    uint32_t i;
    while(current_objects[i].kind != none && ++i<bound)
    {
        ;
    }

    if (i == bound) //there aren't free slots
    {
        return -1;
    }
    
    current_objects[i] = _obj; //bytewise copy
    return 0;
}

/*
    @BRIEF: analyzeRanita
        Gets the ranita movement, updates it's position, and analyze if a collision
        or win condition happened, and acts upon them
*/
void analyzeRanita(void)
{
    //GET INPUT HERE!!
    switch(getInput_stub())
    {
        case no_movement:
            break;
    
        case up:  
        case right:
        case left:
        case down:
            break;
        
        default:
            puts("Received a broken input from getInput!");
            break;  
    }

    

}

void updateLogicMatrix(void)
{
    static const uint32_t  bound = sizeof(current_objects)/sizeof(*current_objects); 
    uint32_t i;
}