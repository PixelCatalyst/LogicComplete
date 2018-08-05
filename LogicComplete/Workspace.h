#pragma once

#include "Widget.h"

namespace gui
{
    class Workspace : public gui::Widget
    {
    private:
        sf::RenderTexture renderTarget;
        sf::View camera;
        sf::Sprite presentation;

        void applySize(int width, int height) override;
    public:
        const sf::Sprite& draw() override;
        void update() override;

        virtual sf::Vector2i getPos() const override;
        void setPos(int x, int y) override;
        sf::Vector2i getVisibleSize() const override;

        void onResize(const VectorChange2i& parentSize) override;

        Workspace();
    };
}
