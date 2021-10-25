#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#include "Vector2D.h"

/* Get the resource path for resources located in res/subDir */
std::string getResourcePath(const std::string& subDir = "");

/* draw utilities */
void set_pixel(SDL_Renderer*, int , int , Uint8 , Uint8 , Uint8 , Uint8 );
void draw_circle(SDL_Renderer*, int , int , int , Uint8 , Uint8 , Uint8 , Uint8);
float getDistance(Vector2D, Vector2D);
float getLenght(Vector2D);
void draw_line(SDL_Renderer*, int, int, int, int);
Vector2D getPerpendicularVector(Vector2D,bool);