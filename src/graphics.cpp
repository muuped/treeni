#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"


/*  Graphics
 *   Holds all the information dealing with the graphics of the game
 */

Graphics::Graphics(){
    SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer); // Ikkunan koko
    SDL_SetWindowTitle(_window, "Janin peli"); //Ikkunan nimi
}
Graphics::~Graphics(){
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath){
    if(_spriteSheets.count(filePath) == 0){
        _spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return _spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle){
    SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip(){
    SDL_RenderPresent(_renderer);
}

void Graphics::clear(){
    SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
    return _renderer;
}
