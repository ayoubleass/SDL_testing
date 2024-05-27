#include "../headers/main.h"
#include <stdio.h>
/**
 * 
 * init_instance -
 * @instance: 
 * @return:
 */

int init_instance(SDL_Instance * instance,  SDL_Renderer**gRenderer){
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return (0);
    }
    instance->window = SDL_CreateWindow( "maze", 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN );
    if(instance->window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        free(instance);
        SDL_Quit();
        return (0);   
    }
    /* Initialize renderer color*/
    *gRenderer = SDL_CreateRenderer(instance->window, -1, 0);
    if(*gRenderer == NULL) {
        printf("renderer  could not be created! SDL_Error: %s\n",  SDL_GetError());
        free(instance);
        SDL_Quit();
        return (0);  
    }
    return (1);
}
void move(int key, SDL_Rect **p);

void process(int *running, SDL_Rect *p){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            *running = 0;
            break;
        case SDL_KEYDOWN:
            move(event.key.keysym.sym, &p);
            break; 
    }
}

void move(int key, SDL_Rect **p){
    switch(key) {
        case SDLK_z: 
            (*p)->y -= 32/2;
            break;
        case SDLK_s: 
            (*p)->y += 32/2;
            break;
        case SDLK_d:
            (*p)->x += 32/2;
            break;
        case SDLK_q:
            (*p)->x -= 32/2;
            break;
    }
}


void close(SDL_Instance *instance, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( instance->window );
    instance->window = NULL;
    SDL_Quit();
}
