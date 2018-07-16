#include "player.h"
#include "../motor.h"
Player::Player() :Drawable2D()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::onInit()
{
    m_rect = Rectangle2D(Vector2D(200,400),Vector2D(60,102));
    m_color = DrawColor(204,51,0,255);
    m_enable=true;
}

void Player::onUpdate()
{
    Control pad = Motor::I().Control_PAD();
    Vector2D vel(0,0);
    if(pad.Pressed_Right())
    {
        vel.SetX(5);
    }
    else if(pad.Pressed_Left())
    {
        vel.SetX(-5);
    }
    m_rect.GetPos()=m_rect.GetPos()+vel;
}

