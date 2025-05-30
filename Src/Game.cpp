#include "Game.h"
#include "Box2DHelper.h"

Game::Game(sf::RenderWindow& win) : world(b2Vec2(0.0f, 9.8f)), window(win), renderer(win, 100.0f) {
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;

    // Crear plano inclinado (30 grados, coeficiente de rozamiento 0.3)
    plane = Box2DHelper::CreateInclinedPlane(world, 0.0f, 5.0f, 10.0f, 30.0f, 0.3f);

    // Crear caja (1x1 metro, densidad 1.0, rozamiento 0.3)
    box = Box2DHelper::CreateBox(world, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.3f);
}

void Game::Update(float deltaTime) {
    world.Step(timeStep, velocityIterations, positionIterations);
}

void Game::Render() {
    renderer.DrawBody(plane);
    renderer.DrawBody(box);
}