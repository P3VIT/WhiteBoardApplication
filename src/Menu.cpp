#include "Menu.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Menu::Menu() {
    toolBarMenu = sf::RectangleShape({800.f,60.f});
    toolBarMenu.setFillColor(sf::Color{248,248,248,255});
    toolBarMenu.setPosition(0, 0);
};

bool Menu::isOnMenu(sf::Vector2f mousePos) {
    float mouse_x = mousePos.x;
    float mouse_y = mousePos.y;


    // float x1 = toolBarMenu.getPosition().x;
    // float y1 = toolBarMenu.getPosition().y;
    // float x2 = x1 + toolBarMenu.getSize().x;
    // float y2 = y1 + toolBarMenu.getSize().y;

    // if ((mouse_x >= x1) and (mouse_x < x2) and (mouse_y >= y1) and (mouse_y < y2)) {
    //     toolBarMenu.setFillColor(sf::Color::Magenta);
    // } else {
    //     toolBarMenu.setFillColor(sf::Color{248,248,248,255});
    // }

    return false;
}

void Menu::render(sf::RenderWindow& window) {
    if (icon.loadFromFile("../assets/eraser.png")) {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    } else {
        cerr << "Failed to load icon file" << endl;
    }

    window.draw(toolBarMenu);
}