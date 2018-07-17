#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

#include "../node2d.h"
#include "color.h"

class Drawable2D:public Node2D{
public:
    Drawable2D();
    virtual ~Drawable2D();
    void setVisible(bool v=true);
    bool &isVisible();
    virtual void Draw();
    void setColor(ColorHEX color);
protected:
    bool m_visible;
    ColorHEX m_color;
};

#endif // DRAWABLE_H
