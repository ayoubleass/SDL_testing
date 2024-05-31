#include "../headers/maze.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>




int map[mapWidth][mapHeight] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};
   






int main(int argc, char **argv) {
    SDL_Instance *instance = malloc(sizeof(SDL_Instance));
    SDL_Event e;
    Dir  direction;
    Plan plan;  
    SDL_Rect player = {.x = SCREEN_WIDTH/4, .y = SCREEN_HEIGHT/4, .w = 15, .h = 15};
    int w = SCREEN_WIDTH , h = SCREEN_HEIGHT;
    direction.x = -1, direction.y = 0; 
    plan.x = 0, plan.y = 0.66;
    (void)argc, (void)argv;
    int game_running = init_instance(instance);

   
 
    while (game_running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                game_running = 0;
            }
            if(e.type == SDL_KEYDOWN) {
                if(e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_RIGHT){
                    rotate(e.key.keysym.sym, &direction, &plan);
                }else{
                    move(e.key.keysym.sym ,&player, &direction, 10);
                }

            }
        }
        draw_map(instance);
        debug(instance , &player, &direction, &plan);      
        SDL_RenderPresent(instance->renderer);

    }
    destroy_instance(instance);
    free(instance);
    return 0;
}    
          