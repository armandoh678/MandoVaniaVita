#include "node2d.h"
#include "motor.h"

Node2D::Node2D()
{
    m_parent = nullptr;
    m_enable = false;

}
Node2D::~Node2D() {}
void Node2D::onInit() {}
void Node2D::onUpdate() {}
void Node2D::onTerminate() {}
void Node2D::onChangeParent() {}
void Node2D::onChildDelete(Node2D *child) {}
void Node2D::onChildDettach(Node2D *child) {}
void Node2D::onChildAttach(Node2D *child) {}
void Node2D::onCollide(std::vector<Node2D*> nodes) {}
void Node2D::DeleteChild(int pos)
{
    Node2D *child = m_vchilds[pos];
    child->terminate();
    child->DeleteChilds();
    m_vchilds.erase(m_vchilds.begin()+pos);
    onChildDelete(child);
    delete child;
}
void Node2D::AttachChild(Node2D *child)
{
    m_vchilds.push_back(child);
    child->m_parent=this;
    child->onChangeParent();
    onChildAttach(child);
    child->init();
}
void Node2D::DetachChild(Node2D *child)
{
    for(int i=0; i<m_vchilds.size(); i++)
    {
        if(child==m_vchilds[i])
        {
            m_vchilds.erase(m_vchilds.begin()+i);
            onChildDettach(child);
            child->m_parent=nullptr;
            break;
        }
    }
}
void Node2D::ChangeParent(Node2D *parent)
{
    m_parent->DetachChild(this);
    parent->AttachChild(this);
}
void Node2D::DeleteChilds()
{
    for(int i=0; i<m_vchilds.size(); i++)
    {
        Node2D *child = m_vchilds[i];
        child->terminate();
        child->DeleteChilds();
        DetachChild(child);
        delete child;
    }
}

void Node2D::update()
{
    onUpdate();
    for(Node2D* child:m_vchilds)
    {
        if(child->m_enable)
        {
            child->update();
        }
    }
}
void Node2D::init()
{
    onInit();
    for(Node2D* child:m_vchilds)
    {
        child->init();
    }
}
void Node2D::terminate()
{
    onTerminate();
    for(Node2D* child:m_vchilds)
    {
        child->onTerminate();
    }
}

bool Node2D::getEnable()
{
    return m_enable;
}
void Node2D::setEnable(bool en)
{
    m_enable=en;
}

void Node2D::initAsStatic(b2Vec2 pos, b2Vec2 sz,b2World* wrd)
{
    m_world = wrd;
    b2BodyDef bodydef;
    bodydef.position.Set(pos.x,pos.y);
    bodydef.type = b2_staticBody;
    b2PolygonShape box;
    box.SetAsBox(sz.x,sz.y);
    m_body = m_world->CreateBody(&bodydef);
    m_body->CreateFixture(&box,0.0f);

    m_drawSize.x =sz.x*2.f;
    m_drawSize.y = sz.y*2.f;
    m_drawSize2.x =sz.x;
    m_drawSize2.y = sz.y;
}

void Node2D::initAsDynamic(b2Vec2 pos, b2Vec2 sz,b2World* wrd,
                           float32 dens,float32 fricc,float32 rest,bool fixRot)
{
    m_world = wrd;
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x,pos.y);
    bodyDef.fixedRotation=fixRot;
    m_body = m_world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(sz.x,sz.y);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = dens;
    fixtureDef.friction = fricc;
    fixtureDef.restitution = rest;

    m_body->CreateFixture(&fixtureDef);

    m_drawSize.x =sz.x*2.f;
    m_drawSize.y = sz.y*2.f;
    m_drawSize2.x =sz.x;
    m_drawSize2.y = sz.y;

}

void Node2D::initAsKinematc(b2Vec2 pos, b2Vec2 sz,b2World* wrd,
                            float32 dens,float32 fricc,float32 rest,bool fixRot)
{
    m_world = wrd;
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.position.Set(pos.x,pos.y);
    bodyDef.fixedRotation=fixRot;
    m_body = m_world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(sz.x,sz.y);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = dens;
    fixtureDef.friction = fricc;
    fixtureDef.restitution = rest;

    m_body->CreateFixture(&fixtureDef);

    m_drawSize.x =sz.x*2.f;
    m_drawSize.y = sz.y*2.f;
    m_drawSize2.x =sz.x;
    m_drawSize2.y = sz.y;
}

