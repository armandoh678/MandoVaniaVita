#ifndef NODE2D_H
#define NODE2D_H
#include <vector>

class Vector2D
{
    friend class Rectangle2D;
    friend class Node2D;
public:
    Vector2D();
    Vector2D(int x,int y);
    virtual ~Vector2D();
    void SetX(int x);
    void SetY(int y);
    int GetX();
    int GetY();
    Vector2D& operator+(const Vector2D& other) // copy assignment
    {
        this->m_y+=other.m_y;
        this->m_x+=other.m_x;
        return *this;
    }

    Vector2D& operator-(const Vector2D& other) // copy assignment
    {
        this->m_y-=other.m_y;
        this->m_x-=other.m_x;
        return *this;
    }
protected:
    int m_x;
    int m_y;
};

class Rectangle2D
{
public:
    friend class Node2D;
    Rectangle2D();
    Rectangle2D(Vector2D pos,Vector2D sz);
    virtual ~Rectangle2D();
    bool isColliding(Rectangle2D &rec);
    void SetPos(Vector2D &pos);
    void SetSiz(Vector2D &siz);
    Vector2D &GetPos();
    Vector2D &GetSiz();
protected:
    Vector2D m_pos;
    Vector2D m_size;
};

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

    Rectangle2D &GetRectangle();
    Rectangle2D SetRectangle(Rectangle2D rect);

protected:
    int m_enable;
    Rectangle2D m_rect;
    std::vector<Node2D*> m_vchilds;
    Node2D* m_parent;
};

#endif // NODE2D_H
