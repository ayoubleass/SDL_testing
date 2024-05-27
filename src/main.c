#include "../headers/main.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


SDL_Renderer* gRenderer = NULL;
int runing = 1;


int map[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,1,1,1,1,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};
   




int main(int argc, char **argv) {
    SDL_Instance *instance = malloc(sizeof(SDL_Instance));
    SDL_Rect player;
    player.x = 32;
    player.y  = 32;
    player.w=15;
    player.h = 15;
    float pdeltaX, pdeltaY, pa; 

    (void) argc, (void) argv;
    runing = init_instance(instance, &gRenderer);
    while(runing){ 
        process(&runing, &player, &pa, &pdeltaX, &pdeltaY);
        draw(gRenderer, &player ,map);        
         /*Update the screen */
        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(gRenderer, player.x, player.y, player.x + pdeltaX * 10,
        player.y + pdeltaY * 10);

        SDL_RenderPresent(gRenderer);
    }
    close(instance, gRenderer);
    free(instance); 
    return (0);
}
            
          