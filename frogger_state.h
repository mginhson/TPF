#ifndef FROGGER_STATE_H
#define FROGGER_STATE_H

/*
@BRIEF:
    Se define la estructura y matriz asociada que controla el estado del juego en si. Esto NO responde al estado "grafico" de las cosas en el momento
    Por ejemplo, los autos y troncos tienen movimientos continuos, es trabajo de game_logic definir si un tronco se encuentra o no en una 
    celda. Por ejemplo, si solo un cuarto del tronco esta en una celda donde la ranita puede saltar, no deberia aparecer en la matriz, mas si graficamente
    se debe representar.
*/

#include <stdint.h>

#define MAP_Y_MAX 16
#define MAP_X_MAX 16


//Si se divide en dos structs distintas, cada modulo puede agarrar solo la parte que realmente le interesa (?checkear)

//Objetos moviles en el mapa que sean amenazas
typedef enum{
    none = 0,
    car,
    log,
    _objects_count;
}map_threat_t;

typedef struct{
    
    map_threat_t threat;
}cell_logic_t;

typedef struct{


}cell_graphic_t;

typedef struct{
    cell_logic_t logic;
    cell_graphic_t graphic;    
}cell_t;

extern cell_t state_matrix[MAP_Y_MAX][MAP_X_MAX];

#endif