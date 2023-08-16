#include "drawer.h"
#include <stdio.h>

#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#define scale_factor 100

void drawer_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        fprintf(stderr, "Error initalizing sdl");
    }

  window = SDL_CreateWindow(
    "maze_generation",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    MAZE_SIZE * scale_factor,
    MAZE_SIZE * scale_factor,
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

void drawer_render(maze *m, int target) { 
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0,255);


    for(int i = 0; i < (MAZE_SIZE * MAZE_SIZE); i++) { 
        cell c = m->cells[i];

        if (c.visited) {

        
          int x = ((c.x) * scale_factor);
          int y = ((c.y) * scale_factor);

          printf("***************\n");
          printf("For cell at index i: %d\n, top wall says: %d\n bot wall: %d\n",i, c.top_wall, c.bottom_wall);
          printf("***************\n");

          //top
          if (c.top_wall) { 
              SDL_RenderDrawLine(renderer, 
                                y, 
                                x, 
                                y + scale_factor,
                                x);
          };

          //bot line
          if (c.bottom_wall) {
          SDL_RenderDrawLine(renderer, 
                              y, 
                              x + scale_factor, 
                              y + scale_factor, 
                              x + scale_factor);
          };


                      ////left line
          if (c.left_wall) {
              SDL_RenderDrawLine(renderer, 
                                  y, 
                                  x, 
                                  y, 
                                  x + scale_factor);

          }

          if (c.left_wall) {
              SDL_RenderDrawLine(renderer, 
                                  y, 
                                  x, 
                                  y, 
                                  x + scale_factor);

          }

                      //right line
          if (c.right_wall) {
              SDL_RenderDrawLine(renderer, 
                                  y + scale_factor, 
                                  x, 
                                  y + scale_factor, 
                                  x + scale_factor);
          }
        }

                            

          //SDL_Rect rect = { x ,y , scale_factor, scale_factor};
          //SDL_RenderDrawRect(renderer, &rect);
          int t_x = ((m->cells[target].x) * scale_factor);
          int t_y = ((m->cells[target].y) * scale_factor);
          SDL_Rect rect = { t_x , t_y , scale_factor/2, scale_factor/2};
          SDL_RenderFillRect(renderer, &rect);
    }





    SDL_RenderPresent(renderer);
    SDL_Delay(10);
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