#include "drawable.h"
#include "../motor.h"

DrawColor::DrawColor()
{
    m_r=255;
    m_g=255;
    m_b=255;
    m_a=255;

}
DrawColor::DrawColor(int r,int g,int b, int a)
{
    m_r=r;
    m_g=g;
    m_b=b;
    m_a=a;
}
DrawColor::~DrawColor() {}
int &DrawColor::getR()
{
    return m_r;
}
int &DrawColor::getG()
{
    return m_g;
}
int &DrawColor::getB()
{
    return m_b;
}
int &DrawColor::getA()
{
    return m_a;
}

Drawable2D::Drawable2D() :Node2D()
{
    m_visible=true;
}

Drawable2D::~Drawable2D()
{
}

void Drawable2D::setVisible(bool v)
{
    m_visible=true;
}
bool &Drawable2D::isVisible(){
    return m_visible;
}
void Drawable2D::setColor(DrawColor color){
    m_color=color;
}
void Drawable2D::Draw()
{
}

Sprite::Sprite()
{
}
Sprite::~Sprite()
{
}
void Sprite::setImage()
{
}
void Sprite::Draw()
{
}

