#include "stdafx.h"

#include "Widget.h"

namespace gui
{
    sf::Vector2i Widget::getMaxSize() const
    {
        constexpr int maxInteger = std::numeric_limits<int>::max();
        return sf::Vector2i(maxInteger, maxInteger);
    }
    sf::Vector2i Widget::getMinSize() const
    {
        return sf::Vector2i(0, 0);
    }

    sf::Vector2i Widget::getRevisedPos(const VectorChange2i& parentSize) const
    {
        sf::Vector2i currPos = getPos();
        return anchor.getRevisedPos(currPos, parentSize);
    }

    sf::Vector2i Widget::getRevisedSize(const VectorChange2i& parentSize) const
    {
        sf::Vector2i currSize = getSize();
        return anchor.getRevisedSize(currSize, parentSize);
    }

    sf::Vector2i Widget::getVisibleSize() const
    {
        return size;
    }

    sf::Vector2i Widget::getSize() const
    {
        return size;
    }

    void Widget::setSize(int width, int height)
    {
        size.x = width;
        size.y = height;
        sf::Vector2i minSize = getMinSize();
        sf::Vector2i maxSize = getMaxSize();
        width = std::clamp(width, minSize.x, maxSize.x);
        height = std::clamp(height, minSize.y, maxSize.y);
        applySize(width, height);
    }

    bool Widget::isVisible() const
    {
        return visible;
    }

    void Widget::show()
    {
        visible = true;
    }

    void Widget::hide()
    {
        visible = false;
    }

    void Widget::setAnchor(const Anchor& anchor)
    {
        this->anchor = anchor;
    }

    void Widget::onResize(const VectorChange2i& parentSize)
    {
        sf::Vector2i revisedPos = getRevisedPos(parentSize);
        sf::Vector2i revisedSize = getRevisedSize(parentSize);
        setPos(revisedPos.x, revisedPos.y);
        setSize(revisedSize.x, revisedSize.y);
    }

    Widget::Widget(int width, int height) :
        size(width, height),
        visible(true)
    {}
}
