#include "main.h"
#include <stdio.h>
/**
 * 
 * init_instance -
 * @instance: 
 * @return:
 */

int init_instance(SDL_Instance * instance, const int SCREEN_WIDTH,const int SCREEN_HEIGHT){
    int imgFlags;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return (1);
    }
    instance->window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if(instance->window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        free(instance);
        return (1);   
    }
    imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return (1);
    }
    instance->screenSurface = SDL_GetWindowSurface(instance->window);
    return (0);
}


SDL_Surface* load_surface(char *path, SDL_Instance *instance)
{
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
        SDL_Quit();
    }else{
        optimizedSurface = SDL_ConvertSurface( loadedSurface, instance->screenSurface->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface );
    }
    return optimizedSurface;
}



void close(SDL_Instance *instance,  SDL_Surface* surface_test)
{
    SDL_FreeSurface( surface_test);
    SDL_DestroyWindow( instance->window );
    instance->window = NULL;
    SDL_Quit();
}
