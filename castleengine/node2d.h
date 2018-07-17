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


    void initAsStatic(b2Vec2 pos, b2Vec2 sz,b2World* wrd);
    void initAsDynamic(b2Vec2 pos, b2Vec2 sz,b2World* wrd,float32 dens =1.0f,float32 fricc =0.3f,float32 rest =0.3f);
    void initAsKinematc(b2Vec2 pos, b2Vec2 sz,b2World* wrd,float32 dens =1.0f,float32 fricc =0.3f,float32 rest =0.3f);


protected:
    b2Body* m_body;
    b2Vec2 m_drawSize;
    b2Vec2 m_drawSize2;
    b2World *m_world;
    int m_enable;
    std::vector<Node2D*> m_vchilds;
    Node2D* m_parent;
};

#endif // NODE2D_H
