#include "Canvas.hpp"
#include <iostream>

using namespace std;

Canvas::Canvas(unsigned int width, unsigned int height) {
    wasPressedLastFrame = false;
};

void Canvas::plotLineHigh(sf::Image& img, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;
    int x = x0;

    for (int y = y0; y < y1; y++) {
        img.setPixel(x, y, sf::Color::Red);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else {
            D = D + 2*dx;
        }
    }
}


void Canvas::plotLineLow(sf::Image& img, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int err = (2 * dy) - dx;
    int y = y0;

    for (int x = x0; x < x1; x++) {
        img.setPixel(x, y, sf::Color::Red);
        if (err > 0) {
            y = y + yi;
            err = err + (2 * (dy - dx));
            
        } else {
            err = err + 2 * dy;
        }
    }
}

void Canvas::plotLine(sf::Image& img, sf::Vector2f position) {
    int x0 = lastMosPos.x;
    int y0 = lastMosPos.y;

    int x1 = position.x;
    int y1 = position.y;
    

    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            plotLineLow(img,x1, y1, x0, y0);
        } else {
            plotLineLow(img, x0, y0, x1, y1);
            
        }
    } else {
        if (y0 > y1) {
            plotLineHigh(img, x1,y1,x0,y0);
        } else {
            plotLineHigh(img, x0, y0, x1, y1);
        }
    }

    lastMosPos=position;
}


void Canvas::drawPixel(sf::Image& img, sf::Vector2f position) {
    for (int i = position.x;  i < position.x + 1; i++) {
        for (int j = position.y; j < position.y + 1; j ++){
                img.setPixel(i, j, sf::Color::Red);
        }
    }
    lastMosPos=position;
}

// this function will only be called when the left button is released
void Canvas::resetMousePos(sf::Vector2f position) {
    wasPressedLastFrame = false;
}

void Canvas::render(sf::Image& img, sf::Texture& tex, sf::RenderWindow& window) {
    tex.update(img);
    sf::Sprite sprite(tex);
    window.draw(sprite);
}

void Canvas::updateSroke(sf::Image& img, sf::Texture& tex, sf::Vector2f position, sf::RenderWindow& window, bool isPressed) {
    if (isPressed && wasPressedLastFrame) {
        // if the left mouse button is pressed right now and was last frame we draw a line
        plotLine(img, position);
    } else if (!wasPressedLastFrame && isPressed) {
        // if the mouse was not pressed last frame but is now we draw only a pixel
        lastMosPos = position;
        drawPixel(img, position);
    }

    wasPressedLastFrame = isPressed;

    
    render(img, tex, window);
}   

