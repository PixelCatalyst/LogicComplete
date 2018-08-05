#pragma once

#include <vector>

namespace gui
{
    class Widget;

    class Window
    {
    private:
        sf::RenderWindow target;
        sf::Vector2i size;
        std::vector<Widget*> childWidgets;

        void onClose();
        void adjustView(unsigned width, unsigned height);
        void onResize(const sf::Event& event);
    public:
        void draw();
        void dispatchEvents();
        bool isOpen() const;

        void attachWidget(Widget* widget);

        void init(unsigned width, unsigned height, const std::string& title);
    };
}
