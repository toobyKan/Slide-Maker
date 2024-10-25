#ifndef SDL_RENDERER_HPP
#define SDL_RENDERER_HPP

#include <SDL2/SDL.h>
#include "graphical_interface.hpp"


class SDLRenderer : public IGraphicsRenderer{
public:
    SDLRenderer(int window_size);
    ~SDLRenderer();

    bool initialize() override;
    void render() override;
    void clearScreen() override;
    void presentScreen() override;


private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    int window_size_;
};

#endif
