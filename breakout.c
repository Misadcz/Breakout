#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "breakout.h"
#include "brick.h"




void walls(SDL_Renderer* renderer,  SDL_Rect rect)
{

    SDL_SetRenderDrawColor(renderer, 136, 136, 136, 1); // Nastavení barvy na červenou
    for(int i = 0 ; i < 25 ; i++)
        {
            SDL_RenderFillRect(renderer, &rect);
            rect.x += rect.w;
            SDL_RenderFillRect(renderer, &rect);
        }
        rect.x = 0;

       for(int i = 0 ; i < 18 ; i++)
        {
            rect.x = 0;
            SDL_RenderFillRect(renderer, &rect);
            rect.x = 480;
            SDL_RenderFillRect(renderer, &rect);
            
            if( i == 17)
            {
                rect.h = 10;
                rect.y += rect.w;
                SDL_SetRenderDrawColor(renderer,3, 201, 169,1 );
                rect.x = 0;
                SDL_RenderFillRect(renderer, &rect);
                SDL_SetRenderDrawColor(renderer,241, 130, 141, 1 ); 
                rect.x = 480; 
                SDL_RenderFillRect(renderer, &rect);  
            }
            else
            {
               rect.y += rect.h; 
            }
        }
        

        return;
}




void checkCollision(SDL_Renderer* renderer, int *x, int *y, int *score, SDL_bool *reset, SDL_Rect ball, int val1, int val2)
{
for(int i=0; i<COL*ROW; i++)
    {
        brickers(i,val1,val2);
        if((SDL_HasIntersection(&brick, &ball))&&bricks[i])
        {
                bricks[i] = 0;
            
            if(ball.x >= brick.x)
                *x = 3;
            
            if(ball.x <= brick.x)
                *x = -3;

            if(ball.y >= brick.y)
                *y = 5;

            if(ball.y <= brick.y)
                *y = -5;
            

            if(i%6==0)
                *score += 50;
            if(i%6==1)
                *score += 20;
            if(i%6==2)
                *score += 10;
            if(i%6==3)
                *score += 5;
            if(i%6==4)
                *score += 2;
            if(i%6==5)
                *score += 1;

        }
        
        if(bricks[i])
            *reset = 0;
        
        SDL_RenderFillRect(renderer,&ball);
            
    }
        
    return ;
}

void render(SDL_Renderer* renderer, SDL_Rect ball, SDL_Rect board)
{       
        

        SDL_SetRenderDrawColor(renderer,255,99,71,1);
        SDL_RenderFillRect(renderer,&ball);
        SDL_RenderFillRect(renderer,&board);
        SDL_RenderPresent(renderer);
        
        SDL_SetRenderDrawColor(renderer,0,0,0,1);    
        SDL_RenderClear(renderer);
        
        SDL_Delay(1000 / 60);
        return;
}

void collisionWall( SDL_Rect ball,int *x, int *y)
{
if(ball.x >= 475)
        {
           *x = -3;
        }
        if(ball.x <=20)
        {
            *x = 3;
        }
         if(ball.y <= 80)
        {
            *y = 5;
        }

    return;
}

void outChangeDirection(SDL_Rect ball,int mouseX,int *x, int *y)
{
    *y = -5;
                    if(ball.x > mouseX-30)
                    { 
                        *x= -3;
                    }
                    else if(ball.x < mouseX-30)
                    {  
                        *x = 3;
                    }
                    else
                    {

                    }

        return;
}

void collisionBoard(SDL_Rect board, SDL_Rect ball, int *x, int *y, int *last, int mouseX)
{
if (SDL_HasIntersection(&board, &ball))
    {
        *y = -5;
        if(*last > mouseX)
                    { 
                        *x= -3;
                        *y = -5;
                    }
        if(*last<= mouseX)
        {  
            *x = 3;
            *y = -5;
        }
    }
    *last = mouseX;
    return;
}


void ballMove(SDL_Rect * ball, int x, int y)
{
    ball->x += x;
    ball->y += y;

    return;
}

void winChecker(int *won)
{
*won = 1;
        for(int i=0; i<COL*ROW; i++)
        {
            
            if(bricks[i] == 1)
                *won = 0;
        }
        return;
}

void inputFile(int *val1, int *val2)
{
    char line[15];
    char *token;

    FILE *f;
    f = fopen ("position.txt","r");
    fgets(line, sizeof(line), f);
    *val1 = atoi(strtok(line, ";"));
    *val2 = atoi(strtok(NULL, ";"));

    fclose(f);

    return;
}
