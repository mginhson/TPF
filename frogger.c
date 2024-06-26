#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "frogger_state.h"
#include "game_logic.h"

int main(int argc, char **argv)
{
    initializeGameLogic();
    nextLogicTick();
        
    return 0;
}