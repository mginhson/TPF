#ifndef OBJECTS_H
#define OBJECTS_H
#include <stdint.h>
/*
    @BRIEF: Se definen los objetos posibles, analizados separadamente
    por la etapa de logica y renderizado
*/

typedef enum{
    none,
    street,
    log,
    short_log,
    long_log,
    car1,
    car2,
    car3,
    object_kind_count,
    frog, 
    tortle,
    grass, 
    fly,
    death,
    track1,
    track2,
    bush,
    water,
    leaf,
    bush_leaf,
    object_kind_count,
}object_kind_t;



/*
  Todos los objetos son posicionados por sus coordenadas (x,y), las
  cuales hacen referencia a la esquina superior izquierda del objeto
  (x,y)-->|------------|
          |    LOG     | 
          |------------|
*/

typedef struct{
    object_kind_t kind;
    int32_t x,y; //position
    int32_t dx,dy; //velocity
    uint16_t dist_x,dist_y;
}object_t;
/*
    BRIEF:  objectSize
    Returns the memory size in bytes that needs to be allocated 
    to create a new object, the memory MUST be allocated by the caller!
*/

typedef struct{
    object_kind_t obj_kind;
}cell_t;



/*
    BRIEF: objectCreate y objectDestroy
    Inicializa el objeto, usando la memoria alocada por el caller. A definir los parametros iniciales
    Destroy libera la memoria de un objeto para su eliminacion.
*/

object_t * objectCreate(void * _allocated_memory, object_kind_t _kind);
void objectDestroy(object_t * _object_to_destroy);





#endif