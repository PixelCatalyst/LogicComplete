#include "stdafx.h"

#include "Application.h"

void Application::draw()
{
    mainWindow.draw();
}

void Application::update()
{
    mainWindow.dispatchEvents();
    workspace.update();
}

bool Application::isRunning() const
{
    return mainWindow.isOpen();
}

Application::Application()
{
    //TODO Options initialized from config file 
    mainWindow.init(800, 600, "LogicComplete");
    mainWindow.attachWidget(&workspace);

    workspace.setSize(800, 500);
    workspace.setPos(0, 50);
    using gui::Align;
    workspace.setAnchor(gui::Anchor(Align::stretch, Align::stretch));
}
