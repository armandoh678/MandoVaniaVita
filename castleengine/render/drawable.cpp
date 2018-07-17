#include "drawable.h"
#include "../motor.h"

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

void Drawable2D::setColor(ColorHEX color){
    m_color=color;
}

void Drawable2D::Draw()
{
    vita2d_draw_rectangle(m_body->GetPosition().x-m_drawSize2.x, m_body->GetPosition().y-m_drawSize2.y,
                           m_drawSize.x,m_drawSize.y,
                           m_color._color);
}
