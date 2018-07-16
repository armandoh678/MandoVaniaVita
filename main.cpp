#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include "castleengine/motor.h"

int main(int, char**)
{
    Motor::I().init();
    int result = Motor::I().update();
    Motor::I().close();
    sceKernelExitProcess(0);
	return 0;
}
