#pragma once

class Workspace
{
private:
    sf::RenderWindow& parentWindow;
    sf::RenderTexture renderTarget;
    sf::View camera;
    sf::Sprite presentation;
public:
    void draw();
    void update();

    void setPos(unsigned x, unsigned y);
    void setSize(unsigned width, unsigned height);

    Workspace(sf::RenderWindow& parentWindow);
};
