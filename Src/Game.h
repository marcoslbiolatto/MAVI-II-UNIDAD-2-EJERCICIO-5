#ifndef GAME_H
#define GAME_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "SFMLRenderer.h"

class Game {
private:
    b2World world;
    sf::RenderWindow& window; // Agregar ventana como miembro
    SFMLRenderer renderer;
    b2Body* box;
    b2Body* plane;
    float timeStep;
    int32 velocityIterations;
    int32 positionIterations;

public:
    Game(sf::RenderWindow& win); // Actualizar constructor para recibir la ventana
    void Update(float deltaTime);
    void Render();
};

#endif