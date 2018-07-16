#include "renderlayer.h"
#include "render.h"
#include "../motor.h"
RenderLayer::RenderLayer()
{

}

RenderLayer::~RenderLayer()
{

}
void RenderLayer::addDrawable(Drawable2D* dr)
{
    m_drawables.push_back(dr);
}
void RenderLayer::delDrawable(Drawable2D* dr)
{
    for(int i=0; i<m_drawables.size(); i++)
    {

        if(dr==m_drawables[i])
        {
            m_drawables.erase(m_drawables.begin()+i);
        }
    }
}
void RenderLayer::clearDrawables()
{
    m_drawables.clear();
}

int RenderLayer::draw()
{
    int i=0;
    for(Drawable2D *dr:m_drawables){
        if(dr->isVisible()){
            dr->Draw();
            i++;
        }
    }
    return i;
}

