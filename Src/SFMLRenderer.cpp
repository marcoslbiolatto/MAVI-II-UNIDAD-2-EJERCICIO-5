#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(sf::RenderWindow& win, float ppm) : window(win), pixelsPerMeter(ppm) {}

void SFMLRenderer::DrawBody(b2Body* body) {
    sf::Shape* shape = nullptr;
    for (b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext()) {
        switch (fixture->GetType()) {
        case b2Shape::e_polygon: {
            b2PolygonShape* poly = (b2PolygonShape*)fixture->GetShape();
            sf::ConvexShape* convex = new sf::ConvexShape(poly->m_count);
            for (int i = 0; i < poly->m_count; ++i) {
                b2Vec2 vertex = body->GetWorldPoint(poly->m_vertices[i]);
                convex->setPoint(i, sf::Vector2f(vertex.x * pixelsPerMeter, vertex.y * pixelsPerMeter));
            }
            convex->setFillColor(body->GetType() == b2_dynamicBody ? sf::Color::Red : sf::Color::Green);
            shape = convex;
            break;
        }
        case b2Shape::e_edge: {
            b2EdgeShape* edge = (b2EdgeShape*)fixture->GetShape();
            b2Vec2 v1 = body->GetWorldPoint(edge->m_vertex1);
            b2Vec2 v2 = body->GetWorldPoint(edge->m_vertex2);
            sf::VertexArray* line = new sf::VertexArray(sf::Lines, 2);
            (*line)[0].position = sf::Vector2f(v1.x * pixelsPerMeter, v1.y * pixelsPerMeter);
            (*line)[1].position = sf::Vector2f(v2.x * pixelsPerMeter, v2.y * pixelsPerMeter);
            (*line)[0].color = sf::Color::Green;
            (*line)[1].color = sf::Color::Green;
            window.draw(*line);
            delete line;
            break;
        }
        }
        if (shape) {
            window.draw(*shape);
            delete shape;
        }
    }
}