#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
 
const int width = 300;
const int height = 200; 

char vx = 1;
char vy = 1;

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow(
        "Press any key to close!", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0
    );

    SDL_Renderer* ren = SDL_CreateRenderer(win, 0, 0);

    SDL_FRect rect = {
        .x = 10.0f, .y = 10.0f,
        .w = 30.0f, .h = 30.0f
    };

    // NOTE THAT THIS DOES NOT TAKE DELTA INTO ACCOUNT

    char running = 1;
    while (running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            switch (ev.type) {
                case SDL_QUIT:
                case SDL_KEYDOWN:
                    running = 0;
            }
        }

        if (rect.x + rect.w > width || rect.x < 0.0f)
            vx = -vx;
        
        if (rect.y + rect.h > height || rect.y < 0.0f)
            vy = -vy;

        rect.x += 0.005 * vx;
        rect.y += 0.005 * vy;

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderFillRectF(ren, &rect);
        SDL_RenderPresent(ren);
    }

    return 0;
}