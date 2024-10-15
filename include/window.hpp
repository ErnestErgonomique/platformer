#pragma once

#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow {
private:
    float width = 1280;
    float height = 720;
public:
    Window();
    ~Window();
};
