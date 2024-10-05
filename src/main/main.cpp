#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "soupe.hpp"

// get system time in nanoseconds
long long nanoTime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
    ).count();
}

int main() {
    // gameLoop attributes
    const int FPS = 60;
    double renderInterval = 1000000000 / FPS;
    double delta = 0;
    long long lastTime = nanoTime();
    long long currentTime;

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

    while (window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // gameLoop management
        currentTime = nanoTime();
        delta += (currentTime - lastTime) / renderInterval;
        lastTime = currentTime;

        if (delta >= 1) {
            // sprite movement management
            switch (spriteDirection) {
            float coords[2];
            case -1:
                coords[0] = sprite.getPosition().x;
                coords[1] = sprite.getPosition().y;
                sprite.setPosition(coords[0] - 0.2, coords[1]);
                if (coords[0] <= 0) spriteDirection = 1;
                break;
            case 1:
                coords[0] = sprite.getPosition().x;
                coords[1] = sprite.getPosition().y;
                sprite.setPosition(coords[0] + 0.2, coords[1]);
                if (coords[0] >= width) spriteDirection = -1;
                break;
            }
            window.clear();
            window.draw(sprite);
            window.display();
        }
    }
    return 0;
}
