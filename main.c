#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL]; 
const int SCREEN_WIDTH = 740;
const int SCREEN_HEIGHT = 680;

int  loadMedia(SDL_Instance *instance)
{
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = load_surface( "images/azue.png" , instance);
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        return  (1);
    }
    
    return 0;
}


int main(int argc, char **argv) {
    SDL_Event e;
    bool quit = false;
    SDL_Surface* current_surface;
    SDL_Instance *instance = malloc(sizeof(SDL_Instance));   
    SDL_Rect stretchRect;

    printf("yes");
    (void) argc, (void) argv;
    if (init_instance(instance, SCREEN_WIDTH, SCREEN_HEIGHT) != 0)
        return (1);
    if (loadMedia(instance) != 0) return (1);
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;
    current_surface =  gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] ;
    SDL_BlitScaled(current_surface, NULL, instance->screenSurface, &stretchRect );
    SDL_UpdateWindowSurface(instance->window);
    while( quit == false ){ 
        while( SDL_PollEvent( &e ) ){
            if( e.type == SDL_QUIT ) quit = true;
           
        }
    }
    close(instance, current_surface);
    free(instance); 
    return (0);
}
          