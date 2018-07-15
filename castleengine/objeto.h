#ifndef OBJETO_H
#define OBJETO_H
#include <string.h>

class Objeto
{
public:
    Objeto();
    virtual ~Objeto();
    void setNombre(std::string nombre);
    std::string getNombre();
    virtual std::string toString();
protected:
    std::string m_nombre;
};

#endif // OBJETO_H
