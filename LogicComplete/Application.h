#pragma once

#include "Workspace.h"

class Application
{
private:
    sf::RenderWindow mainWindow;
    Workspace workspace;

    void adjustWindow(unsigned width, unsigned height);
public:
    void draw();
    void update();
    void handleEvents();

    bool isRunning() const;

    Application();
};
