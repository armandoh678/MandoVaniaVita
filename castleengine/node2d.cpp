#include "node2d.h"
#include "motor.h"
Vector2D::Vector2D()
{
    m_x=1;
    m_y=1;
}
Vector2D::Vector2D(int x,int y)
{
    m_x=x;
    m_y=y;
}
Vector2D::~Vector2D() {}

void Vector2D::SetX(int x)
{
    m_x=x;
}
void Vector2D::SetY(int y)
{
    m_y=y;
}
int Vector2D::GetX()
{
    return m_x;
}
int Vector2D::GetY()
{
    return m_y;
}


Rectangle2D::Rectangle2D() {}
Rectangle2D::Rectangle2D(Vector2D pos,Vector2D sz)
{
    m_pos=pos;
    m_size=sz;
}
Rectangle2D::~Rectangle2D() {}
bool  Rectangle2D::isColliding(Rectangle2D &rec)
{
    if (m_pos.m_x < (rec.m_pos.m_x+rec.m_size.m_x) && (m_pos.m_x+m_size.m_x) > rec.m_pos.m_x &&
            m_pos.m_y > (rec.m_pos.m_y+rec.m_size.m_y) && (m_pos.m_y+m_size.m_y) < rec.m_pos.m_y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void  Rectangle2D::SetPos(Vector2D &pos)
{
    m_pos=pos;
}
void  Rectangle2D::SetSiz(Vector2D &siz)
{
    m_size=siz;
}
Vector2D  &Rectangle2D::GetPos()
{
    return m_pos;
}
Vector2D  &Rectangle2D::GetSiz()
{
    return m_size;
}


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
