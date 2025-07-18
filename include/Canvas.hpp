#include <SFML/Graphics.hpp>

class Canvas {
public:
    Canvas(unsigned int width, unsigned int height);
    void updateSroke(sf::Image& img, sf::Texture& tex, sf::Vector2f position, sf::RenderWindow& window, bool isPressed);
    void plotLine(sf::Image& img, sf::Vector2f position);
    void plotLineHigh(sf::Image& img, int x0, int y0, int x1, int y1);
    void plotLineLow(sf::Image& img, int x0, int y0, int x1, int y1);
    void resetMousePos(sf::Vector2f position);
    void drawPixel(sf::Image& img, sf::Vector2f position);
    void render(sf::Image& img, sf::Texture& tex, sf::RenderWindow& window);
private:
    sf::RenderTexture texture_;
    sf::Sprite sprite_;
    sf::Color backgroundColor_;
    sf::Vector2f lastMosPos;
    sf::Vector2f posMosReleased;
    sf::Image img;
    bool wasPressedLastFrame;
    bool isPressedThisFrame;

    bool released;
};