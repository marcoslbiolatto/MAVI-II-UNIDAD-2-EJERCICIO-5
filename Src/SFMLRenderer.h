#ifndef SFML_RENDERER_H
#define SFML_RENDERER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SFMLRenderer {
private:
    sf::RenderWindow& window;
    float pixelsPerMeter;

public:
    SFMLRenderer(sf::RenderWindow& window, float ppm = 100.0f);
    void DrawBody(b2Body* body);
};

#endif