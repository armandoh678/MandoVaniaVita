#include "player.h"
#include "../motor.h"
Player::Player() :Drawable2D()
{
}

Player::~Player()
{
    //dtor
}

void Player::onInit()
{
    m_enable=true;
}

void Player::onUpdate()
{
    b2Vec2 vel(0.0f,0.0f);
    if(Motor::I().Control_PAD().Just_Pressed_Left()){
        vel.x=-500;
    }else if(Motor::I().Control_PAD().Just_Pressed_Right()){
        vel.x=500;
    }
    if(Motor::I().Control_PAD().Just_Pressed_Up()){
        vel.y=-500;
    }else if(Motor::I().Control_PAD().Just_Pressed_Down()){
        vel.y=500;
    }
    m_body->SetLinearVelocity(vel);

}



