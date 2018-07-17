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

    b2Vec2 gravity(0.0f, 10.0f);
    m_world = new b2World(gravity);
    RenderLayer *layer = new RenderLayer();
    m_RLayers.push_back(layer);


    Player *player = new Player();
    player->initAsDynamic(b2Vec2(400,200),b2Vec2(50,100),m_world);
    layer->addDrawable(player);
    this->AttachChild(player);

    Drawable2D *piso = new Drawable2D();
    piso->initAsStatic(b2Vec2(480,522),b2Vec2(960,44),m_world);
    layer->addDrawable(piso);

}

void Escene::onUpdate(){
    m_world->Step(Motor::I().DeltaTime()/1000.0f,8,3);
}
