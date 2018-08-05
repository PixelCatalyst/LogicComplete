#include "stdafx.h"

#include "Workspace.h"

namespace gui
{
    const sf::Sprite& Workspace::draw()
    {
        renderTarget.clear(sf::Color::Black);
        //TODO
        renderTarget.display();
        presentation.setTexture(renderTarget.getTexture(), true);
        return presentation;
    }

    void Workspace::update()
    {
        renderTarget.setView(camera);
    }

    sf::Vector2i Workspace::getPos() const
    {
        sf::Vector2f exactPos = presentation.getPosition();
        return sf::Vector2i(exactPos.x, exactPos.y);
    }

    void Workspace::setPos(int x, int y)
    {
        presentation.setPosition(x, y);
    }

    sf::Vector2i Workspace::getVisibleSize() const
    {
        sf::Vector2i visibleSize(0, 0);
        if (isVisible())
        {
            sf::Vector2u targetSize = renderTarget.getSize();
            visibleSize.x = targetSize.x;
            visibleSize.y = targetSize.y;
        }
        return visibleSize;
    }

    void Workspace::applySize(int width, int height)
    {
        bool targetValid = renderTarget.create(width, height);
        if (targetValid)
        {
            camera.setSize(sf::Vector2f(width, height));
            camera.setCenter(sf::Vector2f(width / 2.0f, height / 2.0f));
            show();
        }
        else
            hide();
    }

    void Workspace::onResize(const VectorChange2i& parentSize)
    {
        Widget::onResize(parentSize);
        //TODO
    }

    Workspace::Workspace() :
        Widget(0, 0)
    {
        hide();
    }
}
