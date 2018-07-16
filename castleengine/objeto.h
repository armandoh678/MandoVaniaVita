#ifndef OBJETO_H
#define OBJETO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


class Objeto
{
public:
    Objeto();
    virtual ~Objeto();
    void setNombre(const char* nombre);
    const char* getNombre();
    virtual const char* toString();
protected:
    const char* m_nombre;
};

#endif // OBJETO_H
