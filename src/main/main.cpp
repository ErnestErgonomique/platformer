#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

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

    sf::RenderWindow window(sf::VideoMode(width, heigt), "Super fenetre");

    while (window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
