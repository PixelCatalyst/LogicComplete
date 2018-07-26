#pragma once

#include "Workspace.h"

class Application
{
private:
    sf::RenderWindow mainWindow;
    Workspace workspace;
public:
    void draw();
    void update();
    void handleEvents();

    bool isRunning() const;

    Application();
};
