#include "player.hpp"

Player::Player() {
    this->x = 0.f;
    this->y = 0.f;
    this->velocity = 8.f;
    this->playerSprite = new sf::Sprite();
    autoLoadTextures();
}

Player::~Player() {
    delete this->playerSprite;
}

const sf::Sprite& Player::getSprite() {
    return *playerSprite;
}

void Player::autoLoadTextures() {
    sf::Texture mechaArbre;
    if (mechaArbre.loadFromFile("assets/mecha_arbre.png")) {
        playerTextures.push_back(mechaArbre);
        std::cout << "\033[32mTexture successfully loaded\033[0m" << std::endl;
    } else {
        std::cerr << "\033[31mError : texture file not found\033[0m"
        << std::endl;
    }
}

void Player::update() {
    this->playerSprite->setTexture(playerTextures.at(0));
    this->playerSprite->setScale(0.1f, 0.1f);
}
