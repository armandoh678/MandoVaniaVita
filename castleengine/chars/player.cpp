#include "player.h"
#include "../motor.h"
Player::Player() :Drawable2D()
{
    m_jumpTime =0;
}

Player::~Player()
{

}

void Player::onInit()
{
    m_enable=true;

}

void Player::onUpdate()
{/*
    b2Vec2 vel(0.0f,0.0f);
    if(Motor::I().Control_PAD().Pressed_Left())
    {
        vel.x=-50000.0f;
    }
    else if(Motor::I().Control_PAD().Pressed_Right())
    {
        vel.x=50000.0f;
    }
    vel.y=980.0f;


    if(m_jumpTime==0 && Motor::I().Control_PAD().Just_Pressed_Cross())
    {
        m_jumpTime+=Motor::I().DeltaTime();
    }


    m_body->SetLinearVelocity(vel);*/
}














