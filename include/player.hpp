#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Player {
private:
    float x;
    float y;
    float velocity;
    std::vector<sf::Texture> playerTextures;
    sf::Sprite* playerSprite = nullptr;

    void autoLoadTextures();
public:
    Player();
    ~Player();
    const sf::Sprite& getSprite();
    void update();
};
