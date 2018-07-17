#ifndef MOTOR_H
#define MOTOR_H
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "debug.h"
#include "objeto.h"
#include "render/render.h"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include "escene.h"

class Control
{
    friend class Motor;
public:
    Control();
    ~Control();
    bool Pressed_Left();
    bool Just_Pressed_Left();
    bool Pressed_Right();
    bool Just_Pressed_Right();
    bool Pressed_Up();
    bool Just_Pressed_Up();
    bool Pressed_Down();
    bool Just_Pressed_Down();

    bool Pressed_Cross();
    bool Just_Pressed_Cross();
    bool Pressed_Triangle();
    bool Just_Pressed_Triangle();
    bool Pressed_Square();
    bool Just_Pressed_Square();
    bool Pressed_Circle();
    bool Just_Pressed_Circle();

    bool Pressed_L();
    bool Just_Pressed_L();
    bool Pressed_R();
    bool Just_Pressed_R();

    bool Pressed_Start();
    bool Just_Pressed_Start();
    bool Pressed_Select();
    bool Just_Pressed_Select();

protected:
    bool m_buttons[12];
    bool m_ant_buttons[12];
};


class Motor
{
public:
    void init();
    void close();
    int update();
    /// Singleton   ///
    static Motor& I()
    {
        static Motor    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    Control &Control_PAD();

    Render &Renderer();
    double &Framerate();
    double &DeltaTime();
    ///--------------///
    void PrintStr(std::string str);

private:
    /// Simgleton   ///
    Motor(Motor const&)               = delete;
    void operator=(Motor const&)  = delete;
    ///--------------///

    Motor();
    virtual ~Motor();
    Render m_render;
    SceCtrlData pad;
    Control m_gpad;
    Escene m_escena;

    /*Para Calcular Los FPS*/
    clock_t m_deltaTime;
    double m_deltaTimeD;
    double clockToMilliseconds(clock_t ticks);
    double m_fps;


};

#endif // MOTOR_H
