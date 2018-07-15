#include "objeto.h"

Objeto::Objeto()
{
}

Objeto::~Objeto()
{
}
void Objeto::setNombre(std::string nombre)
{
    m_nombre=nombre;
}

std::string Objeto::getNombre()
{
    return m_nombre;
}

std::string Objeto::toString()
{
    return m_nombre;
}
