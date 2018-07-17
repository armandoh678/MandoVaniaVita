#ifndef PALYER_H
#define PALYER_H
#include "../render/drawable.h"

class Player :public Drawable2D
{
public:
    Player();
    virtual ~Player();
    virtual void onInit();
    virtual void onUpdate();
    virtual void onCollide(std::vector<Node2D*> &nodes);
protected:

};

#endif // PALYER_H
