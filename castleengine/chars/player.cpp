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
    float velx=0;
    float vely=0;
    if(Motor::I().Control_PAD().Just_Pressed_Left()){
        velx=-5;
    }else if(Motor::I().Control_PAD().Just_Pressed_Right()){
        velx=5;
    }
    if(Motor::I().Control_PAD().Just_Pressed_Up()){
        vely=-5;
    }else if(Motor::I().Control_PAD().Just_Pressed_Down()){
        vely=5;
    }

}



