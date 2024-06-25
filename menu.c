#include <stdio.h>

void menu_principal (int option){
    
    enum options_principal {PLAY_GAME = 1, HIGH_SCORES, QUIT_GAME};
    
    switch (option){
        case PLAY_GAME:
            start_game ();
            break;
        case HIGH_SCORES:
            show_scores ();
            break;
        case QUIT_GAME:
            end_game();
            break;
    }

}


void menu_secundaria (int option){
    
    enum options_secundario {RESUME = 1, RESTART, QUIT_GAME};
    
    switch (option){
        case RESUME:
            resume_game ();
            break;
        case RESTART:
            start_game ();
            break;
        case QUIT_GAME:
            back_to_principal();
            break;
    }

}