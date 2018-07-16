#ifndef RENDERLAYER_H
#define RENDERLAYER_H
#include "drawable.h"
#include <sstream>
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>
class Render;
class RenderLayer
{
public:
    RenderLayer();
    virtual ~RenderLayer();
    void addDrawable(Drawable2D*);
    void delDrawable(Drawable2D*);
    void clearDrawables();
    int draw();
private:
    std::vector<Drawable2D*> m_drawables;
};

#endif // RENDERLAYER_H
