#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "breakout.h"
#include "ttf.h"
#include "brick.h"


int main ()
{ 
    int score = 0, won = 0, lives = 4, textW = 0, textH = 0, mouseX = 0, x = 0 , y = 0 , out = 0, last = 0, start = 1;
    char result[10], liveprint[10];

  //  SDL_Init(SDL_INIT_VIDEO);     // DELA MEMORY LEAKY 193bytes

    SDL_Window* window = SDL_CreateWindow("Breakout", 200, 200, 500, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Color color = { 255, 255, 255,1 }, endcolor = { 255, 0, 0,1 }, wincolor = { 0, 255, 0,1 };

    TTF_Init();
    TTF_Font * font = TTF_OpenFont("arcade.ttf", 48);
    
    sprintf(liveprint,"%d",lives);
    sprintf(result,"%d",score);

    SDL_Surface * surface = TTF_RenderText_Solid(font,result, color);
    SDL_Surface * surface2 = TTF_RenderText_Solid(font,liveprint, color);
    SDL_Surface * surface3 = TTF_RenderText_Solid(font,liveprint, color);

    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Texture * texture3 = SDL_CreateTextureFromSurface(renderer, surface3);

    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
    SDL_QueryTexture(texture2, NULL, NULL, &textW, &textH);
    SDL_QueryTexture(texture3, NULL, NULL, &textW, &textH);

    SDL_Event event;

    SDL_bool quit = 0;
    SDL_bool reset = 1;

    SDL_Rect wall = {0,50,20,30};
    SDL_Rect board = {250,580,60,10};
    SDL_Rect ball = {250,300,4,8};
    SDL_Rect scorerect = { 100, 0, textW, textH };
    SDL_Rect livesrect = { 250, 0, textW, textH };
    SDL_Rect winlose = { 150, 250, 200, 50 };
    
   SDL_SetRenderDrawColor(renderer,71, 222, 203,1);

    brick.w = (500 - (COL))/COL;
    brick.h = 15;

    int val1, val2;

    inputFile(&val1,&val2);
    
    while(!quit)
    {
        
    checkCollision(renderer,&x,&y,&score, &reset, ball,val1,val2);
    
    if(reset)
        fillBricks();

    while(SDL_PollEvent(&event))
    {
            if(event.type == SDL_QUIT)
                quit = SDL_TRUE;

            if(event.key.keysym.sym == SDLK_ESCAPE)
                quit = SDL_TRUE;

        SDL_GetMouseState(&mouseX, NULL);

            if((mouseX+board.w/2 < 480)&&(mouseX-board.w/2 > 20))
            {
            board.x = mouseX-board.w/2;  
            }


            if(out == 1)
            {
                outChangeDirection(ball,mouseX,&x,&y);
                out = 0;
            }
    }

    collisionWall(ball,&x,&y);
    collisionBoard(board,ball,&x,&y,&last,mouseX);
    

    if(ball.y>=600|| start == 1)
    {
        start = 0;
        out = 1;
        y = 0;
        x = 0;
        ball.y = board.y - 10;
        ball.x = board.x;
        lives -= 1;
    }

        ballMove(&ball,x,y);
        
        if(lives < 1)
        {
            printfFinal(renderer,surface3,texture3,winlose,"PROHRA",endcolor,&quit, font);
        }
        else if(won == 1)
        {
            printfFinal(renderer,surface3,texture3,winlose,"VYHRA",wincolor,&quit, font);
             
        }
        else
        {
            drawThem(renderer,val1,val2);
            winChecker(&won);
            walls(renderer, wall);
            headScore(renderer,score,lives ,texture,texture2, surface, surface2,scorerect,livesrect,font,color);
            render(renderer,ball,board);
        }

    
    
    }

    SDL_FreeSurface(surface);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);

    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}