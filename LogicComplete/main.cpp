#include "stdafx.h"

#include "Application.h"

int __stdcall WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application app;
    while (app.isRunning())
    {
        app.handleEvents();
        app.update();
        app.draw();
    }

    return 0;
}

