#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdlib.h>


#define TILE_SIZE 32
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define EPSILON 1e-6
#define mapWidth 10
#define mapHeight 10
#define PI 3.14159

extern int map[mapWidth][mapHeight];

typedef struct {
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer* renderer;
}SDL_Instance;


typedef struct dir {
    double x;
    double y;
} Dir;

typedef struct plan{
    double x;
    double y;
}Plan;


int init_instance(SDL_Instance * instance);
void destroy_instance(SDL_Instance *instance);
void draw_map(SDL_Instance *instance);
void rotate(int key, Dir *direction, Plan *plan);
void move(int key, SDL_Rect *player, Dir *direction, int move_speed);
void debug(SDL_Instance *instance , SDL_Rect *player, Dir *direction, Plan *plan);

#endif