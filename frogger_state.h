#ifndef FROGGER_STATE_H
#define FROGGER_STATE_H

/*
@BRIEF:
    Se define la estructura y matriz asociada que controla el estado del juego en si. Esto NO responde al estado "grafico" de las cosas en el momento
    Por ejemplo, los autos y troncos tienen movimientos continuos, es trabajo de game_logic definir si un tronco se encuentra o no en una 
    celda. Por ejemplo, si solo un cuarto del tronco esta en una celda donde la ranita puede saltar, no deberia aparecer en la matriz, mas si graficamente
    se debe representar.
*/
#include "objects.h"
#include <stdint.h>

#define MAP_Y_MAX 16
#define MAP_X_MAX 16




typedef struct{
    object_kind_t obj_kind;
}cell_t;

extern cell_t state_matrix[MAP_Y_MAX][MAP_X_MAX];

#endif


/*
OPCIONES PARA DEFINIR LOS ESTADOS DE LAS CELDAS (BY S.PAPPALARDO)

OPCION 1:
        ESTADO DE LA CELDA COMO UN INT
        PUEDE VALE 0 (RANA), 1 (TRONCO), 2 (AUTO), 3 (AGUA), 4 (CALLE), ETC.
        SE CREA UNA MATRIZ DE 16x16 INTS Y CADA INT MUESTRA EL SU VALOR DEL 0 AL 4 MOSTRANDO QUÉ ES
        int Matriz_Estados [16][16];


OPCION 2:
        typedef struct {
            char rana;
            char tronco;
            char auto;
            char agua;
            char calle;
        }estado_celda_t;        // Lo hago con chars para ocupar menos memoria total solo se necesita ver si == 0 o !=0

        estado_celda_t Matriz_Estados [16][16];


*/