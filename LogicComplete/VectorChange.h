#pragma once

template<typename T>
struct VectorChange2
{
    sf::Vector2<T> old;
    sf::Vector2<T> recent;

    T diffY() const
    {
        return recent.y - old.y;
    }

    T diffX() const
    {
        return recent.x - old.x;
    }

    VectorChange2(const sf::Vector2<T>& old, const sf::Vector2<T>& recent) :
        old(old),
        recent(recent)
    {}
};

using VectorChange2f = VectorChange2<float>;
using VectorChange2i = VectorChange2<int>;
using VectorChange2u = VectorChange2<unsigned>;
