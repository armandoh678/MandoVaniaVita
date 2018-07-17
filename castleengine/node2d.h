#ifndef NODE2D_H
#define NODE2D_H
#include <vector>
#include "Box2D/Box2D.h"

class Node2D
{
public:
    Node2D();
    virtual ~Node2D();
    virtual void onInit();
    virtual void onUpdate();
    virtual void onTerminate();
    virtual void onChangeParent();
    virtual void onChildDelete(Node2D *child);
    virtual void onChildDettach(Node2D *child);
    virtual void onChildAttach(Node2D *child);
    virtual void onCollide(std::vector<Node2D*> nodes);

    void DeleteChild(int pos);
    void AttachChild(Node2D *child);
    void DetachChild(Node2D *child);
    void ChangeParent(Node2D *parent);
    void DeleteChilds();

    void update();
    void init();
    void terminate();

    bool getEnable();
    void setEnable(bool en);
    void initShape(float32 x,float32 y,float32 h,float32 w,b2World* w);
protected:
    b2PolygonShape box;
    b2Body* body;
    int m_enable;
    Rectangle2D m_rect;
    std::vector<Node2D*> m_vchilds;
    Node2D* m_parent;
};

#endif // NODE2D_H
