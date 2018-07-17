#include "node2d.h"
#include "motor.h"

Node2D::Node2D(float32 x,float32 y,float32 h,float32 w,b2World* w)
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

Rectangle2D Node2D::SetRectangle(Rectangle2D rect)
{
    m_rect=rect;
}

Rectangle2D &Node2D::GetRectangle()
{
    return m_rect;
}

void Node2D::initShape(float32 x,float32 y,float32 h,float32 w,b2World* w)
{
    b2BodyDef bodDef;
    bodDef.position.Set(x, y);
    box.SetAsBox(h,w);
    body = w->CreateBody(&bodDef);
    body->CreateFixture(&box,0.0f);
}
