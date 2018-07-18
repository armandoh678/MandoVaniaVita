#include "motor.h"

Control::Control() {
    for(int i=0;i<12;i++){
        m_buttons[i]=false;
        m_ant_buttons[i]=false;
    }
}
Control::~Control() {}
bool Control::Pressed_Left()
{
    return m_buttons[0];
}
bool Control::Just_Pressed_Left()
{
    return m_buttons[0] && !m_ant_buttons[0];
}
bool Control::Pressed_Right()
{
    return m_buttons[1];
}
bool Control::Just_Pressed_Right()
{
    return m_buttons[1] && !m_ant_buttons[1];
}
bool Control::Pressed_Up()
{
    return m_buttons[2];
}
bool Control::Just_Pressed_Up()
{
    return m_buttons[2] && !m_ant_buttons[2];
}
bool Control::Pressed_Down()
{
    return m_buttons[3];
}
bool Control::Just_Pressed_Down()
{
    return m_buttons[3] && !m_ant_buttons[3];
}

bool Control::Pressed_Cross()
{
    return m_buttons[4];
}
bool Control::Just_Pressed_Cross()
{
    return m_buttons[4] && !m_ant_buttons[4];
}
bool Control::Pressed_Triangle()
{
    return m_buttons[5];
}
bool Control::Just_Pressed_Triangle()
{
    return m_buttons[5] && !m_ant_buttons[5];
}
bool Control::Pressed_Square()
{
    return m_buttons[6];
}
bool Control::Just_Pressed_Square()
{
    return m_buttons[6] && !m_ant_buttons[6];
}
bool Control::Pressed_Circle()
{
    return m_buttons[7];
}
bool Control::Just_Pressed_Circle()
{
    return m_buttons[7] && !m_ant_buttons[7];
}

bool Control::Pressed_L()
{
    return m_buttons[8];
}
bool Control::Just_Pressed_L()
{
    return m_buttons[8] && !m_ant_buttons[8];
}
bool Control::Pressed_R()
{
    return m_buttons[9];
}
bool Control::Just_Pressed_R()
{
    return m_buttons[9] && !m_ant_buttons[9];
}

bool Control::Pressed_Start()
{
    return m_buttons[10];
}
bool Control::Just_Pressed_Start()
{
    return m_buttons[10] && !m_ant_buttons[10];
}
bool Control::Pressed_Select()
{
    return m_buttons[11];
}
bool Control::Just_Pressed_Select()
{
    return m_buttons[11] && !m_ant_buttons[11];
}


Motor::Motor()
{
     m_deltaTimeD = 0;
     m_fps=60;
}

Motor::~Motor()
{
}

void Motor::init()
{
    Logger_MSGL("Iniciando Motor");
    memset(&pad, 0, sizeof(pad));
    m_render.init();
    Logger_MSGL("Motor Iniciado");
}

void Motor::close()
{
    Logger_MSGL("Cerrando Motor");
    m_render.close();
    Logger_MSGL("Motor Cerrado");
}

int Motor::update()
{

    m_escena.init();
    while(1)
    {
        /////
        clock_t beginFrame = clock();
        /////
        m_render.FrameDebDraw=std::string("Debug:\n");
        m_render.FrameDebDraw+=std::string("Frame Rate: ")+std::to_string(Framerate()).c_str()+std::string("\n");
        m_render.FrameDebDraw+=std::string("Delta Time: ")+std::to_string(DeltaTime()).c_str()+std::string("\n");
        sceCtrlPeekBufferPositive(0, &pad, 1);

        {
            m_gpad.m_buttons[0]=pad.buttons & SCE_CTRL_LEFT;
            m_gpad.m_buttons[1]=pad.buttons & SCE_CTRL_RIGHT;
            m_gpad.m_buttons[2]=pad.buttons & SCE_CTRL_UP;
            m_gpad.m_buttons[3]=pad.buttons & SCE_CTRL_DOWN;

            m_gpad.m_buttons[4]=pad.buttons & SCE_CTRL_CROSS;
            m_gpad.m_buttons[5]=pad.buttons & SCE_CTRL_TRIANGLE;
            m_gpad.m_buttons[6]=pad.buttons & SCE_CTRL_SQUARE;
            m_gpad.m_buttons[7]=pad.buttons & SCE_CTRL_CIRCLE;

            m_gpad.m_buttons[8]=pad.buttons & SCE_CTRL_L1;
            m_gpad.m_buttons[9]=pad.buttons & SCE_CTRL_R1;

            m_gpad.m_buttons[10]=pad.buttons & SCE_CTRL_START;
            m_gpad.m_buttons[11]=pad.buttons & SCE_CTRL_SELECT;
        }

        m_escena.update();

        {
            m_gpad.m_ant_buttons[0]=m_gpad.m_buttons[0];
            m_gpad.m_ant_buttons[1]=m_gpad.m_buttons[1];
            m_gpad.m_ant_buttons[2]=m_gpad.m_buttons[2];
            m_gpad.m_ant_buttons[3]=m_gpad.m_buttons[3];
            m_gpad.m_ant_buttons[4]=m_gpad.m_buttons[4];
            m_gpad.m_ant_buttons[5]=m_gpad.m_buttons[5];
            m_gpad.m_ant_buttons[6]=m_gpad.m_buttons[6];
            m_gpad.m_ant_buttons[7]=m_gpad.m_buttons[7];
            m_gpad.m_ant_buttons[8]=m_gpad.m_buttons[8];
            m_gpad.m_ant_buttons[9]=m_gpad.m_buttons[9];
            m_gpad.m_ant_buttons[10]=m_gpad.m_buttons[10];
            m_gpad.m_ant_buttons[11]=m_gpad.m_buttons[11];

        }

        m_render.draw(m_escena.m_RLayers);

        /////
        clock_t endFrame = clock();

        m_deltaTime = endFrame - beginFrame;

        //if you really want FPS
        m_deltaTimeD= clockToMilliseconds(m_deltaTime);
        m_fps = (60.0d*m_deltaTimeD)/m_deltaTimeD;

        /////

    }
    m_escena.terminate();
}

double Motor::clockToMilliseconds(clock_t ticks)
{
    // units/(units/time) => time (seconds) * 1000 = milliseconds
    return (ticks/(double)CLOCKS_PER_SEC)*1000.0;
}



Render &Motor::Renderer()
{
    return m_render;
}
double &Motor::Framerate()
{
    return m_fps;
}
double &Motor::DeltaTime()
{
    return m_deltaTimeD;
}

Control &Motor::Control_PAD()
{
    return m_gpad;
}
void Motor::PrintStr(std::string str){
    m_render.FrameDebDraw+=str;
}
