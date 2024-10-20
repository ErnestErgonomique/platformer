#pragma once

#include <iostream>

#include "renderer.hpp"
#include "window.hpp"

class Game {
private:
    Window* gameWindow = nullptr;
    Renderer* renderer = nullptr;
    std::vector<Player*> objects;
public:
    Game();
    ~Game();
    Window* getWindow();
    void init();
    void run();
};
