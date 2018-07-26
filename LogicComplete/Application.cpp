#include "stdafx.h"

#include "Application.h"

void Application::adjustWindow(unsigned width, unsigned height)
{
    sf::Vector2f center(width / 2.0, height / 2.0);
    sf::Vector2f size(width, height);
    sf::View adjusted(center, size);
    mainWindow.setView(adjusted);
}

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
        else if (event.type == sf::Event::Resized)
            adjustWindow(event.size.width, event.size.height);
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
