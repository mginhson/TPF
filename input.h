#ifndef INPUT_H
#define INPUT_h

typedef enum{
    no_movement,
    up,down,left,right,
    _movement_count,
}ranita_movement_t;

ranita_movement_t getInput_stub(void);
#endif