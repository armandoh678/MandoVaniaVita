#include "render.h"
#include "../motor.h"
Render::Render()
{
}

Render::~Render()
{
}

void Render::init()
{
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
    pgf = vita2d_load_default_pgf();
    pvf = vita2d_load_default_pvf();

}

void Render::setBackColor(int r,int g,int b,int a)
{
    vita2d_set_clear_color(RGBA8(r, g, b, a));
}

void Render::close()
{
    vita2d_fini();
    vita2d_free_pgf(pgf);
    vita2d_free_pvf(pvf);
}

void Render::draw(std::vector<RenderLayer*> &m_layers)
{

    vita2d_start_drawing();
    vita2d_clear_screen();

    int i = 0;
    for(RenderLayer* rl:m_layers)
    {
        i+=rl->draw();
    }

    vita2d_pgf_draw_text(pgf, 10, 20,
                          RGBA8(255,255,255,255), 0.8f, FrameDebDraw.c_str());

    vita2d_end_drawing();
    vita2d_swap_buffers();

}

void Render::RenderText(int x,int y,unsigned int col, float scale,std::string text){
    vita2d_pgf_draw_text(pgf, x, y,
                          col, scale, text.c_str());
}
