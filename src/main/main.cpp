#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "soupe.hpp"

// gets system time in nanoseconds
long long nanoTime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
    ).count();
}

int main() {
    // classes test
    Soupe soupe("soupe");
    std::cout << soupe.getName() << std::endl;

    // textures and sprites test
    sf::Texture texture;
    if (!texture.loadFromFile("assets/mecha_arbre.png")) {
        std::cerr << "Error while trying to load image" << std::endl;
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);

    sf::FloatRect dimensions = sprite.getGlobalBounds();
    float width = dimensions.width;
    float heigt = dimensions.height;

    int spriteDirection = 1;

    // renderwindow test
    sf::RenderWindow window(sf::VideoMode(width * 2, heigt), "Super fenetre");

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // sprite movement management
        switch (spriteDirection) {
        case -1:
            sprite.move(-7.f, 0.f);
            if (sprite.getPosition().x <= 0) spriteDirection = 1;
            break;
        case 1:
            sprite.move(7.f, 0.f);
            if (sprite.getPosition().x >= width) spriteDirection = -1;
            break;
        }
        
        window.clear();
        window.draw(sprite);
        window.display();

    }
    return 0;
}
