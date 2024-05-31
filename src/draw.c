#include "../headers/maze.h"
#include <math.h>


void rotate(int key, Dir *direction, Plan *plane) {
    double rotation_speed = 0.05;
    double cos_rot = cos(rotation_speed);
    double sin_rot = sin(rotation_speed);

    switch (key) {
        case SDLK_LEFT:
            // Rotate counterclockwise
            {
                double oldDirX = direction->x;
                direction->x = direction->x * cos_rot - direction->y * sin_rot;
                direction->y = oldDirX * sin_rot + direction->y * cos_rot;

                double oldPlaneX = plane->x;
                plane->x = plane->x * cos_rot - plane->y * sin_rot;
                plane->y = oldPlaneX * sin_rot + plane->y * cos_rot;
            }
            break;

        case SDLK_RIGHT:
            // Rotate clockwise
            {
                double oldDirX = direction->x;
                direction->x = direction->x * cos_rot + direction->y * sin_rot;
                direction->y = -oldDirX * sin_rot + direction->y * cos_rot;

                double oldPlaneX = plane->x;
                plane->x = plane->x * cos_rot + plane->y * sin_rot;
                plane->y = -oldPlaneX * sin_rot + plane->y * cos_rot;
            }
            break; 
        }
}


void move(int key, SDL_Rect *player, Dir *direction, int move_speed) {
    switch (key) {
        case SDLK_UP:
            // Move forward
            player->x += direction->x * move_speed;
            player->y += direction->y * move_speed;
            break;

        case SDLK_DOWN:
            // Move backward
            player->x -= direction->x * move_speed;
            player->y -= direction->y * move_speed;
            break;
    }
}

void draw_map(SDL_Instance *instance){
    SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
    SDL_RenderClear( instance->renderer );
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            SDL_Rect rect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            if (map[y][x] == 1) {
                SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);
            } else {
                SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
            }
            SDL_RenderFillRect(instance->renderer, &rect);
        }
    }

}