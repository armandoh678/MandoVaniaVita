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
    RenderLayer *layer = new RenderLayer();
    Drawable2D *piso =  new Drawable2D();
    piso->setEnable(true);
    piso->SetRectangle(Rectangle2D(Vector2D(0,500),Vector2D(960,44)));
    piso->setColor(DrawColor(102, 51, 0,255));
    Player *pl = new Player();
    this->AttachChild(pl);
    layer->addDrawable(pl);
    layer->addDrawable(piso);
    m_RLayers.push_back(layer);
}

