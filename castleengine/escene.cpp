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
    player->initAsDynamic(b2Vec2(400,200),b2Vec2(25,50),m_world,10.0f,0.3f,1.0f,true);
    layer->addDrawable(player);
    this->AttachChild(player);

    Drawable2D *piso = new Drawable2D();
    piso->initAsStatic(b2Vec2(480,522),b2Vec2(960,10),m_world);
    layer->addDrawable(piso);

    Drawable2D *paredD = new Drawable2D();
    paredD->initAsStatic(b2Vec2(930,272),b2Vec2(10,544),m_world);
    layer->addDrawable(paredD);

    Drawable2D *paredI = new Drawable2D();
    paredI->initAsStatic(b2Vec2(30,272),b2Vec2(10,544),m_world);
    layer->addDrawable(paredI);

    Drawable2D *top = new Drawable2D();
    top->initAsStatic(b2Vec2(480,44),b2Vec2(960,10),m_world);
    layer->addDrawable(top);
}

void Escene::onUpdate()
{
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 8;
    m_world->Step(Motor::I().DeltaTime(),velocityIterations,positionIterations);
}
