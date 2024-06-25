#ifndef OBJECTS_H
#define OBJECTS_H
#include <stdint.h>
/*
    @BRIEF: Se definen los objetos posibles, analizados separadamente
    por la etapa de logica y renderizado
*/

typedef enum{
    none,
    log,
    car,
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
    uint16_t x,y; //position
    uint16_t dx,dy; //velocity
}object_t;
/*
    BRIEF:  objectSize
    Returns the memory size in bytes that needs to be allocated 
    to create a new object, the memory MUST be allocated by the caller!
*/
uint32_t   objectSize(void);

/*
    BRIEF: objectCreate y objectDestroy
    Inicializa el objeto, usando la memoria alocada por el caller. A definir los parametros iniciales
    Destroy libera la memoria de un objeto para su eliminacion.
*/

object_t * objectCreate(void * _allocated_memory, object_kind_t _kind);
void objectDestroy(object_t * _object_to_destroy);





#endif