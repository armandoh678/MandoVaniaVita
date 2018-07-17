#include "escene.h"
#include "motor.h"

Escene::Escene(): Node2D()
{
}

Escene::~Escene()
{
}

void Escene::onInit()
{
    b2Vec2 gravity(0.0f, -10.0f);
    world = new b2World(gravity);


    RenderLayer *layer = new RenderLayer();
    m_RLayers.push_back(layer);
}

