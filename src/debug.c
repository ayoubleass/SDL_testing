#include "../headers/maze.h"





void debug(SDL_Instance *instance , SDL_Rect *player, Dir *direction, Plan *plan){
    SDL_SetRenderDrawColor( instance->renderer, 0xFF, 0x00, 0x00, 0xFF );        
    SDL_RenderDrawPoint(instance->renderer, player->x, player->y);
    SDL_SetRenderDrawColor(instance->renderer, 0x00, 0x00, 0x00, 0xFF);
    int w = SCREEN_WIDTH;
    for (int x = 0; x <= w; x++) {
        double cameraX = 2 * x / (double)w - 1;
        double rayDirX = direction->x + plan->x * cameraX;
        double rayDirY = direction->y + plan->y * cameraX;

        double endX = player->x + rayDirX * 50;
        double endY = player->y + rayDirY * 50;

        SDL_SetRenderDrawColor(instance->renderer, 200, 200, 0, 255); 
        SDL_RenderDrawLine(instance->renderer, player->x,  player->y, endX, endY);
    }
}