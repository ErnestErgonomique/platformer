#pragma once

#include <iostream>

#include "renderer.hpp"
#include "window.hpp"

class Game {
private:
    Window* gameWindow = nullptr;
    Renderer* renderer = nullptr;
    sf::Texture temporaryTexture;
    sf::Sprite temporarySprite;
public:
    Game();
    ~Game();
    Window* getWindow();
    sf::Sprite& getTemporarySprite();
    void run();
};
