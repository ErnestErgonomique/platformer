#pragma once

#include <vector>

#include "player.hpp"

class Game;

class Renderer {
private:
    Game* game;
    std::vector<Player*> objects;
public:
    Renderer(Game* game);
    void add(Player* player);
    void render();
};
