#include "color.h"

ColorHEX::ColorHEX()
{
    _color=0xFFFFFFFF;
}

ColorHEX::ColorHEX(unsigned int r,unsigned int g,unsigned int b,unsigned int a)
{
    _color = ((r & 0xff) << 24)+((g & 0xff) << 24)+((b & 0xff) << 24) + (a & 0xff);
}

ColorHEX::ColorHEX(float r,float g,float b,float a)
{
    _color = (((int)(r*255.0f) & 0xff) << 24) +(((int)(g*255.0f) & 0xff) << 16) +(((int)(b*255.0f) & 0xff) << 8) + ((int)(a*255.0f) & 0xff);
}

ColorHEX::ColorHEX(unsigned int hex)
{
    _color = hex;
}

ColorHEX::~ColorHEX()
{
    //dtor
}


void ColorHEX::setR(unsigned int r)
{
    _color = ((r & 0xff) << 24)+((_color & 0xff) << 24)+((_color & 0xff) << 24) + (_color & 0xff);

}

void ColorHEX::setG(unsigned int g)
{
    _color = ((_color & 0xff) << 24)+((g & 0xff) << 24)+((_color & 0xff) << 24) + (_color & 0xff);

}

void ColorHEX::setB(unsigned int b)
{
    _color = ((_color & 0xff) << 24)+((_color & 0xff) << 24)+((b & 0xff) << 24) + (_color & 0xff);
}

void ColorHEX::setA(unsigned int a)
{
    _color = ((_color & 0xff) << 24)+((_color & 0xff) << 24)+((_color & 0xff) << 24) + (a & 0xff);
}


unsigned int ColorHEX::getR()
{
    return ((_color & 0xff) << 24);
}

unsigned int ColorHEX::getG()
{
    return ((_color & 0xff) << 16);
}

unsigned int ColorHEX::getB()
{
    return ((_color & 0xff) << 8);
}

unsigned int ColorHEX::getA()
{
    return (_color & 0xff);
}

unsigned int ColorHEX::getHEX()
{
    return _color;
}
