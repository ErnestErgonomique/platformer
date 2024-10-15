#pragma once

class Game;

class Renderer {
private:
    Game* game;
public:
    Renderer(Game* game);
    void render();
};
