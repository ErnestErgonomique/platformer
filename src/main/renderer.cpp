#include "game.hpp"
#include "renderer.hpp"

Renderer::Renderer(Game* game) {
    this->game = game;
}

void Renderer::add(Player* player) {
    this->objects.push_back(player);
}

void Renderer::render() {
    game->getWindow()->clear();
    for (Player* player : objects) {
        game->getWindow()->draw(player->getSprite());
    }
    game->getWindow()->display();
}
