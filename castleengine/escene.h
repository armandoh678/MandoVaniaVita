#ifndef ESCENE_H
#define ESCENE_H
#include "node2d.h"
#include "render/renderlayer.h"
#include "chars/player.h"
#include <vector>
class Motor;
class Escene :public Node2D
{
    friend Motor;
public:
    Escene();
    virtual ~Escene();
    virtual void onInit();
protected:
    std::vector<RenderLayer*> m_RLayers;
};

#endif // ESCENE_H
