#pragma once

#include "VectorChange.h"

namespace gui
{
    class Align
    {
    private:
        class Param
        {
        public:
            enum Type
            {
                topLeftCorner,
                bottomRightCorner,
                Stretch,
                Balance
            };

            bool operator==(const Param& other) const;

            Param(Type tp);
        private:
            Type type;
        };

        Param placement;
    public:
        static const Param topLeft;
        static const Param bottomRight;
        static const Param stretch;
        static const Param balance;

        Param getPlacement() const;

        Align(Param placement);
    };

    class Anchor
    {
    private:
        Align horizontal, vertical;
    public:
        sf::Vector2i getRevisedPos(const sf::Vector2i& currPos, const VectorChange2i& parentSize) const;
        sf::Vector2i getRevisedSize(const sf::Vector2i& currSize, const VectorChange2i& parentSize) const;

        Anchor(Align horizontal = Align::topLeft, Align vertical = Align::topLeft);
    };
}
