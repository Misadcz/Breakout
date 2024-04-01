#ifndef BREAKOUT_H_
#define BREAKOUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define COL 23   //23
#define ROW 6   //6
#define SPACING 1

SDL_bool bricks[ROW*COL];
SDL_Rect brick;


void inputFile(int *val1, int *val2);

void checkCollision(SDL_Renderer* renderer, int *x, int *y, int *score, SDL_bool *reset, SDL_Rect ball, int val1, int val2);
void collisionWall( SDL_Rect ball,int *x, int *y);
void collisionBoard(SDL_Rect board, SDL_Rect ball, int *x, int *y, int *last, int mouseX);
void outChangeDirection(SDL_Rect ball,int mouseX,int *x, int *y);

void ballMove(SDL_Rect * ball, int x, int y);

void walls(SDL_Renderer* renderer,  SDL_Rect rect);

void render(SDL_Renderer* renderer, SDL_Rect ball, SDL_Rect board);

void winChecker(int *won);


#endif
