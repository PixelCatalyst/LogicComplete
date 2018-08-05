#include "stdafx.h"

#include "Window.h"
#include "Widget.h"

namespace gui
{
    void Window::onClose()
    {
        target.close();
    }

    void Window::adjustView(unsigned width, unsigned height)
    {
        sf::Vector2f center(width / 2.0f, height / 2.0f);
        sf::Vector2f size(width, height);
        sf::View adjusted(center, size);
        target.setView(adjusted);
    }

    void Window::onResize(const sf::Event& event)
    {
        adjustView(event.size.width, event.size.height);
        sf::Vector2i recentSize(event.size.width, event.size.height);
        VectorChange2i sizeChange(size, recentSize);
        size = recentSize;
        for (Widget* wg : childWidgets)
            wg->onResize(sizeChange);
    }

    void Window::draw()
    {
        target.clear(sf::Color::White);
        for (Widget* wg : childWidgets)
        {
            if (wg->isVisible())
            {
                const auto& wgImage = wg->draw();
                target.draw(wgImage);
            }
        }
        target.display();
    }

    void Window::dispatchEvents()
    {
        sf::Event event;
        while (target.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                onClose();
            else if (event.type == sf::Event::Resized)
                onResize(event);
        }
    }

    bool Window::isOpen() const
    {
        return target.isOpen();
    }

    void Window::attachWidget(Widget* widget)
    {
        if (widget != nullptr)
        {
            for (unsigned i = 0; i < childWidgets.size(); ++i)
            {
                if (widget == childWidgets[i])
                    break;
                else if ((i + 1) == childWidgets.size())
                    childWidgets.emplace_back(widget);
            }
            if (childWidgets.empty())
                childWidgets.emplace_back(widget);
        }
    }

    void Window::init(unsigned width, unsigned height, const std::string& title)
    {
        sf::VideoMode mode(width, height);
        target.create(mode, title);
        size.x = width;
        size.y = height;
    }
}
