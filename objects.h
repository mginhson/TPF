#ifndef OBJECTS_H
#define OBJECTS_H
#include <stdint.h>
/*
    @BRIEF: Se definen los objetos posibles, analizados separadamente
    por la etapa de logica y renderizado
*/

typedef enum{
    none = 0,
    log,
    short_log,
    long_log,
    car1,
    car2,
    car3,
    female_frog, 
    turtle, 
    fly,
    crocodile,
    snake,
    object_kind_count,
}object_kind_t;


typedef enum{
    water,
    road,
    grass,
    finish_line,
    _background_count,    
}background_t;

typedef struct{
    object_kind_t kind;
    void *sprite;
    uint16_t pixels_x,pixels_y; //What is seen
}object_t;

typedef struct{
    object_kind_t * chosen_lane;
    background_t background;
    double speed;
    uint32_t visible_lane_length;
    int32_t needle,cell_needle;
}lane_t;

/*
  Todos los objetos son posicionados por sus coordenadas (x,y), las
  cuales hacen referencia a la esquina superior izquierda del objeto
  (x,y)-->|------------|
          |    LOG     | 
          |------------|
*/



/*
    BRIEF:  objectSize
    Returns the memory size in bytes that needs to be allocated 
    to create a new object, the memory MUST be allocated by the caller!
*/

typedef struct{
    uint8_t frog          :1;
    uint8_t female_frog   :1;
    uint8_t water         :1;
    uint8_t object        :1;
    uint8_t object_dis    :1;
    uint8_t time          :1;
}cell_t; 


typedef struct{
    int32_t cell_x,cell_y;
}frog_t;





#endif