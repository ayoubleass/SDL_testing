#ifndef MAIN_H
#define MAIN_H

#include <SDL.h>
#include <SDL_image.h>


#define FALSE 0
#define TRUE 1
#define TILE_SIZE 32
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 10
#define MAP_HEIGHT 10



typedef struct {
    SDL_Window* window;
    SDL_Surface* screenSurface;
}SDL_Instance;


/*
typedef struct {
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double fov;
    int w;
    int h;
}Player;
*/



int init_instance(SDL_Instance * instance, SDL_Renderer** gRenderer);
void close(SDL_Instance *instance, SDL_Renderer *renderer);
void process(int *runing, SDL_Rect *p);


void draw(SDL_Renderer *renderer,  SDL_Rect *p,int map[10][10]);
#endif