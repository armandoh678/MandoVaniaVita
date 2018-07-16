#include "objeto.h"
#include "motor.h"
Objeto::Objeto()
{
}

Objeto::~Objeto()
{
}
void Objeto::setNombre(const char* nombre)
{
    m_nombre=nombre;
}

const char* Objeto::getNombre()
{
    return m_nombre;
}

const char* Objeto::toString()
{
    return m_nombre;
}
