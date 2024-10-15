#include "window.hpp"

Window::Window() {
    this->create(sf::VideoMode(width, height), "Plat Game");
    this->setFramerateLimit(60);
}

Window::~Window() {

}
