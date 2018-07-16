#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "../node2d.h"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>
class DrawColor{
public:
    DrawColor();
    DrawColor(int r,int g,int b, int a);
    virtual ~DrawColor();
    int &getR();
    int &getG();
    int &getB();
    int &getA();
private:
    int m_r;
    int m_g;
    int m_b;
    int m_a;
};

class Drawable2D:public Node2D{
public:
    Drawable2D();
    virtual ~Drawable2D();
    void setVisible(bool v=true);
    bool &isVisible();
    virtual void Draw();
    void setColor(DrawColor color);
protected:
    bool m_visible;
    DrawColor m_color;
};

class Sprite:public Drawable2D{
public:
    Sprite();
    virtual ~Sprite();
    void setImage();
    virtual void Draw();
protected:
    std::vector<Rectangle2D> m_frames;
};


#endif // DRAWABLE_H
