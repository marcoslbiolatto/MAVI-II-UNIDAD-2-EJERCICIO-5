#ifndef BOX2D_HELPER_H
#define BOX2D_HELPER_H

#include <Box2D/Box2D.h>
#include <cmath>

class Box2DHelper {
public:
    // Crear un plano inclinado estático
    static b2Body* CreateInclinedPlane(b2World& world, float x, float y, float length, float angleDegrees, float friction) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x, y);
        b2Body* body = world.CreateBody(&bodyDef);

        b2EdgeShape edge;
        float angleRad = angleDegrees * b2_pi / 180.0f;
        edge.SetTwoSided(b2Vec2(0, 0), b2Vec2(length * cos(angleRad), -length * sin(angleRad)));

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &edge;
        fixtureDef.friction = friction; // Coeficiente de rozamiento
        body->CreateFixture(&fixtureDef);
        return body;
    }

    // Crear una caja dinámica
    static b2Body* CreateBox(b2World& world, float x, float y, float width, float height, float density, float friction) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);
        b2Body* body = world.CreateBody(&bodyDef);

        b2PolygonShape box;
        box.SetAsBox(width / 2.0f, height / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        body->CreateFixture(&fixtureDef);
        return body;
    }
};

#endif