#pragma once

class Application
{
private:
    sf::RenderWindow mainWindow;
public:
    void draw();
    void update();
    void handleEvents();

    bool isRunning() const;

    Application();
};
