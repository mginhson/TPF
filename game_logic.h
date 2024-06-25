#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

/*
    @BRIEF:

*/

#include "objects.h"

/*
    @BRIEF nextLogicTick:
    -Actualiza las posiciones de todos los objetos
    -En base a las nuevas posiciones, actualiza la matriz principal
    -Se encarga de eliminar objetos que salieron del mapa y agregar nuevos
*/
void nextLogicTick(void);

#endif