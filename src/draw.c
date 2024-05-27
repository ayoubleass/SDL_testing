#include "../headers/main.h"
#include <math.h>
void drawPlayer(SDL_Renderer *renderer, SDL_Rect*p);
void draw_map(SDL_Renderer *renderer, int map[10][10]);



void draw(SDL_Renderer *renderer,  SDL_Rect *p,int map[10][10]) {
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0xFF );
    SDL_RenderClear(renderer);

    draw_map(renderer, map);
    drawPlayer(renderer, p);
   
}


void drawPlayer(SDL_Renderer *renderer, SDL_Rect *p){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF );        
    SDL_RenderFillRect(renderer, p);
}


void draw_map(SDL_Renderer *renderer, int map[10][10]) {
    SDL_Rect tile_rect;
    SDL_Rect outlineRect;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            tile_rect.x = x * TILE_SIZE;
            tile_rect.y = y * TILE_SIZE;
            tile_rect.w = TILE_SIZE;
            tile_rect.h = TILE_SIZE;

            if (map[y][x] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            SDL_RenderFillRect(renderer, &tile_rect);
            outlineRect.x = tile_rect.x;
            outlineRect.y = tile_rect.y;
            outlineRect.h = TILE_SIZE;
            outlineRect.w = TILE_SIZE;
            SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );        
            SDL_RenderDrawRect( renderer, &outlineRect );
        }
    }
}

