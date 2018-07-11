#include "stdafx.h"

#include "Application.h"

void Application::draw()
{
    mainWindow.clear();
    //TODO
    mainWindow.display();
}

void Application::update()
{
    //TODO
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

Application::Application()
{
    //TODO Options initialized from config file 
    mainWindow.create(sf::VideoMode(400, 300), "LogicComplete");
}
