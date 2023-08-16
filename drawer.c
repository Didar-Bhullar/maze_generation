#include "drawer.h"
#include <stdio.h>

#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#define scale_factor 200

void drawer_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        fprintf(stderr, "Error initalizing sdl");
    }

  window = SDL_CreateWindow(
    "maze_generation",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    3 * scale_factor + 20,
    3 * scale_factor + 20,
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

void drawer_render(maze *m) { 
  SDL_SetRenderDrawColor(renderer, 255,255,255,255);
  //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    for(int i = 0; i < (MAZE_SIZE * MAZE_SIZE); i++) { 
        if (m->cells[i].visited) {
            int x = (m->cells[i].x) * scale_factor;
            int y = (m->cells[i].y) * scale_factor;

            //top line
            SDL_RenderDrawLine(renderer, 
                               x, 
                               y, 
                               x + scale_factor,
                               y);

            //bot line
            SDL_RenderDrawLine(renderer, 
                               x, 
                               y + scale_factor, 
                               x + scale_factor, 
                               y + scale_factor);
            //left line
            SDL_RenderDrawLine(renderer, 
                               x, 
                               y, 
                               x, 
                               y + scale_factor);
            //right line
            SDL_RenderDrawLine(renderer, 
                               x + scale_factor, 
                               y, 
                               x + scale_factor, 
                               y + scale_factor);



            //bot line                  
            //SDL_RenderDrawLine(renderer, 
                              //x,
                              //y + scale_factor, 
                              //x + scale_factor,
                              //y + scale_factor);
            //SDL_Rect rect = { ((m->cells[i].x) * scale_factor),((m->cells[i].y) * scale_factor),
                //scale_factor, scale_factor};

            

            //SDL_RenderDrawRect(renderer, &rect);
        }
    }

  SDL_RenderPresent(renderer);
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