#include "stdafx.h"

#include "Workspace.h"

void Workspace::draw()
{
    renderTarget.clear(sf::Color::Black);
    presentation.setTexture(renderTarget.getTexture());
    parentWindow.draw(presentation);
}

void Workspace::update()
{
    renderTarget.setView(camera);
}

void Workspace::setPos(unsigned x, unsigned y)
{
    presentation.setPosition(x, y);
}

void Workspace::setSize(unsigned width, unsigned height)
{
    renderTarget.create(width, height);
    camera.setSize(sf::Vector2f(width, height));
    camera.setCenter(sf::Vector2f(width / 2.0, height / 2.0));
}

Workspace::Workspace(sf::RenderWindow& parentWindow) :
    parentWindow(parentWindow)
{}
