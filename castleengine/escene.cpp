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
    b2Vec2 gravity(0.0f, 98.0f);
    m_world = new b2World(gravity);
    RenderLayer *layer = new RenderLayer();
    m_RLayers.push_back(layer);

    Player *player = new Player();
    player->initAsDynamic(b2Vec2(400,200),b2Vec2(25,50),m_world,10.0f,0.3f,1.0f);
    layer->addDrawable(player);
    this->AttachChild(player);

    Drawable2D *piso = new Drawable2D();
    piso->initAsStatic(b2Vec2(480,522),b2Vec2(200,40),m_world);
    layer->addDrawable(piso);
}

void Escene::onUpdate()
{
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 8;
    m_world->Step(Motor::I().DeltaTime(),velocityIterations,positionIterations);
}
