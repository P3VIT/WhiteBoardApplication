#include <SFML/Graphics.hpp>
#include <iostream>
#include "Canvas.hpp"
#include "Menu.hpp"

using namespace std;

int main() {
    
    Canvas canvas(800,800);
    Menu menu;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chalkboard Test");

    // Create an image to hold pixel data
    sf::Image img;
    img.create(800, 800, sf::Color::White); // Initially black

    // Create a texture from the image
    sf::Texture tex;
    tex.create(800, 800);
    tex.update(img);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // show the menu
        window.clear();
        

        // Gives the mouse coordinates on the window
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if (menu.isOnMenu(mousePos)) {

        } else {
            canvas.updateSroke(img,tex,mousePos,window, isPressed);
            canvas.render(img, tex, window);   
        }

        menu.render(window);

        window.display();
             
    }

    
    return 0;
}
