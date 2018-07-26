#include "stdafx.h"

#include "Application.h"

void Application::draw()
{
    mainWindow.clear(sf::Color::White);

    workspace.draw();

    mainWindow.display();
}

void Application::update()
{
    workspace.update();
}

void Application::handleEvents()
{
    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mainWindow.close();
    }
}

bool Application::isRunning() const
{
    return mainWindow.isOpen();
}

Application::Application() :
     workspace(mainWindow)
{
    //TODO Options initialized from config file 
    mainWindow.create(sf::VideoMode(400, 300), "LogicComplete");

    workspace.setSize(100, 100);
    workspace.setPos(100, 100);
}
