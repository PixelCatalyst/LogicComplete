#pragma once

#include "Window.h"
#include "Workspace.h"

class Application
{
private:
    gui::Window mainWindow;
    gui::Workspace workspace;
public:
    void draw();
    void update();

    bool isRunning() const;

    Application();
};
