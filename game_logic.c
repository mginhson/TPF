
#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"
#include "objects.h"
#include "frogger_state.h"
#include "input.h"
#include "render.h"


//STATIC FUNCTIONS
static void analyzeRanita(void);
static void updateLogicMatrix(void);
static void generateLevel(uint32_t _level);
static void setLevelBackground(uint32_t _level);
static void wonLevel(void);
static uint32_t calculatePoints(void);



//STATIC GLOBAL VARIABLES
static uint32_t level;
static const object_t road_lane_arquetype[][LANE_LENGTH * 3] = {
    {[2]=car1,[5]=car2,[6]=car3},
};



/*
    @BRIEF: initializeGameLogic
        Initializes the module.
        -Set level at 0
        -Generate the first level

*/

void initializeGameLogic(void)
{
    level = 0;
    generateLevel(level);
    return;
}


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
    @BRIEF: wonLevel 
    -Updates the score
    -Advances to the next level
    -Generates new level
*/
static void wonLevel(void)
{

}

/*
    @BRIEF: Generates the new level:
    -Regenerates map
    -Places ranita at starting position
    -Generates starting objects
    -Updates logic matrix based on new objects and ranita
    -Resets all level-bounded variables

*/

static void generateLevel(uint32_t _level)
{
    static const uint32_t  bound = sizeof(lanes)/sizeof(*lanes); 
    uint32_t i;

    setLevelBackground(_level);
    for (i = 0; i < bound; i++)
    {
        switch(lanes[i].background)
        {
            case water:
            
            case road:
            
            case grass:

            case finish_line:
        }
    }
    
}





    


/*
    @BRIEF: setLevelBackground 
        Sets the background on every lane
*/
static void setLevelBackground(uint32_t _level)
{
    lanes[0].background = grass;
    lanes[1].background = road;
    lanes[2].background = road;
    lanes[3].background = road;
    lanes[4].background = road;
    lanes[5].background = road;
    lanes[6].background = road;
    lanes[7].background = road;
    lanes[8].background = road;
    lanes[9].background = grass;
    lanes[10].background = water;
    lanes[11].background = water;
    lanes[12].background = water;
    lanes[13].background = water;
    lanes[14].background = water;
    lanes[15].background = finish_line;
}