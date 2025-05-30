#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D Inclined Plane Simulation");
    window.setFramerateLimit(60);

    Game game(window); // Pasar la ventana al constructor de Game

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        game.Update(deltaTime);

        window.clear(sf::Color::White);
        game.Render();
        window.display();
    }

    return 0;
}