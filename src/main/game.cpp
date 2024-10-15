#include "game.hpp"

Game::Game() {
    this->gameWindow = new Window();
    this->renderer = new Renderer(this);
    if (!this->temporaryTexture.loadFromFile("assets/mecha_arbre.png")) {
        std::cerr << "Error while trying to load image" << std::endl;
    }
    this->temporarySprite.setTexture(this->temporaryTexture);
    this->temporarySprite.setScale(0.1f, 0.1f);
}

Game::~Game() {
    delete renderer;
    delete gameWindow;
}

Window* Game::getWindow() {
    return this->gameWindow;
}

sf::Sprite& Game::getTemporarySprite() {
    return this->temporarySprite;
}

void Game::run() {
    while (gameWindow->isOpen()) {
        sf::Event event;

        while (gameWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow->close();
            }
        }

        this->renderer->render();
    }
}