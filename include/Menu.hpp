#include <SFML/Graphics.hpp>

class Menu {
public: 
    Menu();
    void render(sf::RenderWindow& window);
    bool isOnMenu(sf::Vector2f mousePos);
private:
    sf::RectangleShape toolBarMenu;
    sf::Text text;
    sf::Image icon;
};