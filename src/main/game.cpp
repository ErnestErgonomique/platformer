#include "game.hpp"

Game::Game() {
    this->gameWindow = new Window();
    this->renderer = new Renderer(this);
}

Game::~Game() {
    delete renderer;
    delete gameWindow;
    for (Player* player : this->objects) {
        delete player;
    }
}

Window* Game::getWindow() {
    return this->gameWindow;
}

void Game::init() {
    objects.push_back(new Player());
    for (Player* player : objects) {
        this->renderer->add(player);
    }
}

void Game::run() {
    while (gameWindow->isOpen()) {
        sf::Event event;

        while (gameWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow->close();
            }
        }

        for (Player* player : objects) {
            player->update();
        }
        this->renderer->render();
    }
}