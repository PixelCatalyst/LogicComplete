#pragma once

#include "Anchor.h"

namespace gui
{
    class Widget //TODO probable hierarchy extensions
    {
    private:
        gui::Anchor anchor;
        sf::Vector2i size;
        bool visible;

        virtual void applySize(int width, int height)
        {}
        virtual sf::Vector2i getMaxSize() const;
        virtual sf::Vector2i getMinSize() const;
    protected:
        sf::Vector2i getRevisedPos(const VectorChange2i& parentSize) const;
        sf::Vector2i getRevisedSize(const VectorChange2i& parentSize) const;
    public:
        virtual const sf::Sprite& draw() = 0;
        virtual void update()
        {}

        virtual sf::Vector2i getPos() const = 0;
        virtual void setPos(int x, int y) = 0;
        virtual sf::Vector2i getVisibleSize() const;
        sf::Vector2i getSize() const;
        void setSize(int width, int height);
        bool isVisible() const;
        void show();
        void hide();
        void setAnchor(const Anchor& anchor);

        virtual void onClick()
        {}
        virtual void onResize(const VectorChange2i& parentSize);

        Widget(int width, int height);
        virtual ~Widget()
        {}
    };
}
