#include "brick.h"


void fillBricks()
{
    for(int i = 0 ; i < COL*ROW ; i++)
        bricks[i] = 1;
    
    return; 
}

void brickers(int i, int val1, int val2)
{
 brick.x=(i%COL)*brick.w+val1;
 brick.y=brick.h*3+(i%ROW)*brick.h+val2;
  return; 
}

void drawThem(SDL_Renderer* renderer, int val1, int val2)
{

for(int i=0; i<COL*ROW; i++)
        { 
            if(i%6==0)
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            if(i%6==1)
                SDL_SetRenderDrawColor(renderer, 255,165, 0, 255);
            if(i%6==2)
                SDL_SetRenderDrawColor(renderer, 255,255, 0, 255);
            if(i%6==3)
                SDL_SetRenderDrawColor(renderer, 0,128,0, 1);
            if(i%6==4)
                SDL_SetRenderDrawColor(renderer, 0,0,255,1);
            if(i%6==5)
                SDL_SetRenderDrawColor(renderer, 75,0, 130, 255);
            if(bricks[i])
            {
            brickers(i,val1,val2);
            SDL_RenderFillRect(renderer, &brick); 
            }
            else 
                bricks[i] =0;

        }
    return;
}
