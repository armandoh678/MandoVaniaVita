#ifndef ESCENE_H
#define ESCENE_H
#include "node2d.h"
#include "render/renderlayer.h"
#include "chars/player.h"
#include <vector>
#include "Box2D/Box2D.h"

class Motor;
class Escene :public Node2D
{
    friend Motor;
public:
    Escene();
    virtual ~Escene();
    virtual void onInit();
protected:
    Player *pl;
    std::vector<RenderLayer*> m_RLayers;
    b2World *world;
};

#endif // ESCENE_H
