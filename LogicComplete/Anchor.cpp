#include "stdafx.h"

#include "Anchor.h"

namespace gui
{
    const Align::Param Align::topLeft = Align::Param(Align::Param::topLeftCorner);
    const Align::Param Align::bottomRight = Align::Param(Align::Param::bottomRightCorner);
    const Align::Param Align::stretch = Align::Param(Align::Param::Stretch);
    const Align::Param Align::balance = Align::Param(Align::Param::Balance);

    bool Align::Param::operator==(const Param& other) const
    {
        return type == other.type;
    }

    Align::Param::Param(Type tp) :
        type(tp)
    {}

    Align::Param Align::getPlacement() const
    {
        return placement;
    }

    Align::Align(Param placement) :
        placement(placement)
    {}

    sf::Vector2i Anchor::getRevisedPos(const sf::Vector2i& currPos, const VectorChange2i& parentSize) const
    {
        sf::Vector2i revisedPos(currPos);
        if (horizontal.getPlacement() == Align::bottomRight)
            revisedPos.x = currPos.x + parentSize.diffX();
        else if (horizontal.getPlacement() == Align::balance)
            revisedPos.x = currPos.x + (parentSize.diffX() / 2);

        if (vertical.getPlacement() == Align::bottomRight)
            revisedPos.y = currPos.y + parentSize.diffY();
        else if (vertical.getPlacement() == Align::balance)
            revisedPos.y = currPos.y + (parentSize.diffY() / 2);

        return revisedPos;
    }

    sf::Vector2i Anchor::getRevisedSize(const sf::Vector2i& currSize, const VectorChange2i& parentSize) const
    {
        sf::Vector2i revisedSize(currSize);
        if (horizontal.getPlacement() == Align::stretch)
            revisedSize.x = currSize.x + parentSize.diffX();
        if (vertical.getPlacement() == Align::stretch)
            revisedSize.y = currSize.y + parentSize.diffY();
        return revisedSize;
    }

    Anchor::Anchor(Align horizontal, Align vertical) :
        horizontal(horizontal),
        vertical(vertical)
    {}
}
