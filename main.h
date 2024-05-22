#ifndef MAIN_H
#define MAIN_H

#include <SDL.h>
#include <SDL_image.h>


enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

typedef struct {
    SDL_Window* window;
    SDL_Surface* screenSurface;
}SDL_Instance;

int init_instance(SDL_Instance * instance, const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
SDL_Surface* load_surface(char *path, SDL_Instance *instance);
void close(SDL_Instance *instance,  SDL_Surface* surface_test);




#endif