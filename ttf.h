#ifndef TTF_H_
#define TTF_H_

#include "breakout.h"

void printfFinal(SDL_Renderer* renderer, SDL_Surface * surface3, SDL_Texture * texture3, SDL_Rect winlose,char result[], SDL_Color color, SDL_bool * quit, TTF_Font * font);
void headScore(SDL_Renderer* renderer, int score, int lives, SDL_Texture * texture, SDL_Texture * texture2, SDL_Surface * surface, SDL_Surface * surface2, SDL_Rect dstrect, SDL_Rect dstrect2, TTF_Font * font, SDL_Color color);

#endif