#include "../headers/main.h"
#include <stdio.h>
#include <math.h>
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
void move(int key, SDL_Rect **p, float **pAngle, float **pdX, float **pdY);

void process(int *running, SDL_Rect *p, float *pAngle, float *pdX, float *pdY){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            *running = 0;
            break;
        case SDL_KEYDOWN:
            move(event.key.keysym.sym, &p, &pAngle, &pdX, &pdY);
            break; 
    }
}

void move(int key, SDL_Rect **p, float **pAngle, float **pdX, float **pdY){
    switch(key) {
        case SDLK_z: 
            (*p)->x -=  **pdX;
            (*p)->y -=  **pdY;
            break;
        case SDLK_s: 
            (*p)->x +=  **pdX;
            (*p)->y +=  **pdY;
            break;
        case SDLK_d:
            **pAngle +=  0.1;
            if (**pAngle > 2 * PI){**pAngle = 0 ;}
                **pdX  = cos(**pAngle) * 5;
                **pdY  = sin(**pAngle) * 5;
            break;
        case SDLK_q:
            **pAngle -=  0.1;
            if (**pAngle < 0){ **pAngle += 2 + PI;}
            **pdX  = cos(**pAngle) * 5;
            **pdY  = sin(**pAngle) * 5;
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
