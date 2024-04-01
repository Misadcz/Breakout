#include "ttf.h"

void headScore(SDL_Renderer* renderer, int score, int lives, SDL_Texture * texture, SDL_Texture * texture2, SDL_Surface * surface, SDL_Surface * surface2, SDL_Rect dstrect, SDL_Rect dstrect2, TTF_Font * font, SDL_Color color)
{
    char result[10];
    char liveprint[10];
       sprintf(result,"%d",score);
        sprintf(liveprint,"%d",lives);

surface = TTF_RenderText_Solid(font,result, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    surface2 = TTF_RenderText_Solid(font,liveprint, color);
    texture2 = SDL_CreateTextureFromSurface(renderer, surface2);

        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);

    
    if(surface)
        SDL_FreeSurface(surface);
    if(surface2)
        SDL_FreeSurface(surface2);


   return;
}

void printfFinal(SDL_Renderer* renderer, SDL_Surface * surface3, SDL_Texture * texture3, SDL_Rect winlose,char result[], SDL_Color color, SDL_bool * quit, TTF_Font * font)
{
    int textW = 0, textH = 0;
    SDL_QueryTexture(texture3, NULL, NULL, &textW, &textH);
            surface3 = TTF_RenderText_Solid(font,result,color);
            texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
            SDL_RenderCopy(renderer, texture3, NULL, &winlose);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000 / 1);
            *quit = 1;
    if(surface3)
        SDL_FreeSurface(surface3);
           return;
}