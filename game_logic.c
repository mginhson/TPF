
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game_logic.h"
#include "objects.h"
#include "frogger_state.h"
#include "input.h"
#include "render.h"


//STATIC FUNCTIONS
static void analyzeMap(void);
static void analyzeRanita(void);
static void updateLogicMap(void);
static void generateLevel(uint32_t _level);
static void setLevelBackground(uint32_t _level);
static void wonLevel(void);
static void debugLanes(void);
static uint32_t calculatePoints(void);



//STATIC GLOBAL VARIABLES
#define ARRSIZE(arr) ((uint32_t)sizeof((arr))/sizeof(*(arr)))
static uint32_t level;


static const object_kind_t road_lane_arquetype[][CELLS_X_MAX * 3] = {
    {[2]=car1,[5]=car2,[6]=car3},
    {[1]=car2},
};

static const object_kind_t water_lane_arquetype[][CELLS_X_MAX * 3] = {
    {[2]=car1,[5]=car2,[6]=car3},
};

static const object_kind_t grass_lane_arquetype[][CELLS_X_MAX * 3] = {
    {[2]=car1,[5]=car2,[6]=car3},
};

static const object_kind_t finish_line_lane_arquetype[][CELLS_X_MAX * 3] = {
    {none},
};


static const uint32_t max_needle_bound = CELLS_X_MAX * 3 * PIXELS_PER_CELL_X;


/*
    @BRIEF: initializeGameLogic
        Initializes the module.
        -Set level at 0
        -Generate the first level

*/

void initializeGameLogic(void)
{
    static const uint32_t  bound = sizeof(lanes)/sizeof(*lanes); 
    uint32_t i;
    level = 0;
    srand(time(NULL));
    
    generateLevel(level);
    debugLanes();
    return;
}


/*
    @BRIEF: nextLogicTick
    -Move the frog (if needed)
    -Move and/or update the lanes 
    -Remove objects that went completely out of bounds
    -Create new objects
    -Analyze wether the frog died or won
    -If the frog won, setup and advance to the next level
    -If it neither died or won, update the logic matrix and handle control over to the render stage
    
*/
void nextLogicTick(void)
{
    getInput_stub();
    analyzeMap();
    //debugLanes();
    render();
}

static void analyzeMap(void)
{
    static const uint32_t  bound = sizeof(lanes)/sizeof(*lanes); 
    uint32_t i,j;
    int32_t last_needle;
    
    for(i=0; i < bound; i++)
    {
        //If timed, move the needle and update the cell needle
        lanes[i].needle=(lanes[i].needle + 4) % max_needle_bound;
        
        last_needle = lanes[i].cell_needle;
        lanes[i].cell_needle = lanes[i].needle / PIXELS_PER_CELL_X;
        if (last_needle != lanes[i].cell_needle) //tengo que actualizar el mapa
        {
            for (j=0;j < ARRSIZE(map[i]);++j)
            {
                map[i][j].background = lanes[i].background;
                map[i][j].kind = lanes[i].chosen_lane[(lanes[i].cell_needle + j)%(3*CELLS_X_MAX)]; 
            }
        }
    }

    
}

static void analyzeRanita(void)
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
    uint32_t i,j,randIndex;

    setLevelBackground(_level);
    for (i = 0; i < bound; i++)
    {
        switch(lanes[i].background)
        {
            case water:
                randIndex =(uint32_t)rand()%ARRSIZE(water_lane_arquetype);
                printf("%d\n",randIndex);
                lanes[i].chosen_lane=&water_lane_arquetype[randIndex];
                lanes[i].speed = (double) rand() / 1000;
                lanes[i].needle =  rand() % max_needle_bound;
                    
                break;
            case road:
                randIndex =(uint32_t)rand()%ARRSIZE(road_lane_arquetype);
                printf("%d\n",randIndex);
                lanes[i].chosen_lane=&road_lane_arquetype[randIndex];
                lanes[i].speed = (double) rand() / 1000;
                lanes[i].needle =  rand() % max_needle_bound;
                break;

            case grass:
                randIndex =(uint32_t)rand()%ARRSIZE(grass_lane_arquetype);
                printf("%d\n",randIndex);
                lanes[i].chosen_lane=&grass_lane_arquetype[randIndex];
                lanes[i].speed = (double) rand() / 1000;
                lanes[i].needle =  rand() % max_needle_bound;
                
                break;
            case finish_line:
                randIndex =(uint32_t)rand()%ARRSIZE(finish_line_lane_arquetype);
                printf("%d\n",randIndex);
                lanes[i].chosen_lane=&finish_line_lane_arquetype[randIndex];
                lanes[i].speed = (double) rand() / 1000;
                lanes[i].needle =  rand() % max_needle_bound;
                
                break;

            default:
                printf("Unknown background on generateLevel!\n");
                break;
        }

        for (j=0;j < ARRSIZE(map[i]);++j)
        {
            map[i][j].background = lanes[i].background;
            map[i][j].kind = lanes[i].chosen_lane[(lanes[i].cell_needle + j)%ARRSIZE(lanes[i].chosen_lane)]; 
        }
    }
    
}


static void debugLanes(void)
{
    static const uint32_t  bound = sizeof(lanes)/sizeof(*lanes); 
    uint32_t i,j;
    printf("ARRSIZE(road_lane_arquetype)=%d\n",ARRSIZE(road_lane_arquetype));
    printf("ARRSIZE(road_lane_arquetype[0])=%d\n",ARRSIZE(road_lane_arquetype[0]));
    for(i=0;i<bound;++i)
    {
        printf("Lane %d:\n\tBackground: %s\n\tneedle: %d\n\tcell_needle: %d\n\tchosen_lane %p\n\tlane contents:\n",i,background_t_string_names[lanes[i].background],lanes[i].needle,lanes[i].cell_needle,lanes[i].chosen_lane);
        for(j=0;j<48;j++)
        {
            
            switch(lanes[i].chosen_lane[j])
            {
                case none:
                    printf(" ");
                    break;
                default:
                    printf(".");
                    break;
            }

            
        }
        printf("\n");
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