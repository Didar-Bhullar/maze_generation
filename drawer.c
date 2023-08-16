#include "drawer.h"
#include <stdio.h>

#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#define padding 10
#define window_size 750

void drawer_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        fprintf(stderr, "Error initalizing sdl");
    }

  window = SDL_CreateWindow(
    "maze_generation",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    window_size + padding,
    window_size + padding,
    0
    );

    if (!window) { 
        fprintf(stderr, "Error creating SDL window");
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) { 
        fprintf(stderr, "Error creating SDL renderer");
    }
}

void drawer_render(maze *m, int delay_ms) { 
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0,255);


    for(int i = 0; i < (m->maze_size * m->maze_size); i++) { 
        cell c = m->cells[i];

        if (c.visited) {

          int scale_factor = window_size / (m->maze_size);
          int x = ((c.x) * scale_factor);
          int y = ((c.y) * scale_factor);

          printf("***************\n");
          printf("For cell at index i: %d\n, top wall says: %d\n bot wall: %d\n",i, c.top_wall, c.bottom_wall);
          printf("***************\n");

          //top
          if (c.top_wall) { 
              SDL_RenderDrawLine(renderer, 
                                x, 
                                y, 
                                x + scale_factor,
                                y);
          };

          //bot line
          if (c.bottom_wall) {
          SDL_RenderDrawLine(renderer, 
                              x, 
                              y + scale_factor, 
                              x + scale_factor, 
                              y + scale_factor);
          };


                      ////left line
          if (c.left_wall) {
              SDL_RenderDrawLine(renderer, 
                                  x, 
                                  y, 
                                  x, 
                                  y + scale_factor);

          }

                      //right line
          if (c.right_wall) {
              SDL_RenderDrawLine(renderer, 
                                  x + scale_factor, 
                                  y, 
                                  x + scale_factor, 
                                  y + scale_factor);
          }
        }
    }

    SDL_RenderPresent(renderer);
    drawer_delay(delay_ms);
}

void drawer_input() { 
  SDL_Event event;
  while(SDL_PollEvent(&event)){ 
    switch(event.type) {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
    }
  }
}

void drawer_delay(int delay_ms) { 
    SDL_Delay(delay_ms);
}