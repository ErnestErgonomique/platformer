#include "game.hpp"
#include "renderer.hpp"

Renderer::Renderer(Game* game) {
    this->game = game;
}

void Renderer::render() {
    game->getWindow()->clear();
    game->getWindow()->draw(game->getTemporarySprite());
    game->getWindow()->display();
}
