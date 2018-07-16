#ifndef RENDER_H
#define RENDER_H
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>
#include <vector>
#include "renderlayer.h"
#include <chrono>
class Render
{
    friend RenderLayer;
public:
    Render();
    virtual ~Render();
    void init();
    void setBackColor(int r,int g,int b,int a);
    void close();
    void draw(std::vector<RenderLayer*> &m_layers);
    std::string FrameDebDraw;
protected:
    vita2d_pgf *pgf;
    vita2d_pvf *pvf;


};

#endif // RENDER_H
