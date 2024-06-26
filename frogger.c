#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include "frogger_state.h"
#include "game_logic.h"

int main(int argc, char **argv)
{
    initializeGameLogic();
    while(1)
    {
        nextLogicTick();
        sleep(1);
        //system("clear");
    }
    return 0;
}