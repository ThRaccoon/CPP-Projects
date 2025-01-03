#include <SFML/Graphics.hpp>
#include <iostream>

#include "MathUtils.h"
#include "Player.h"
#include "Enemy.h"


int main()
{
    //Window
    //--------------------------------------------------------------------------------------
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window");
    window.setFramerateLimit(60);
    //--------------------------------------------------------------------------------------

    //Clases
    //--------------------------------------------------------------------------------------
    Player player;
    player.load();
    player.setupHitbox();

    Enemy enemy1("Assets/Enemy/Orc1/orc1_textureSheet.png");
    enemy1.load();
    enemy1.setupHitbox();
    enemy1.getSprite().setPosition(300, 300);

    Enemy enemy2("Assets/Enemy/Orc2/orc2_textureSheet.png");
    enemy2.load();
    enemy2.setupHitbox();
    enemy2.getSprite().setPosition(300, 200);
    //--------------------------------------------------------------------------------------        

    sf::Time deltaTimeTimer;
    sf::Clock clock;
    sf::Event event;

    float deltaTime = 0.0f;
    float fpsTimeAccumulator = 0.0f;
    int fps = 0;

    //Game loop
    while (window.isOpen())
    {
        deltaTimeTimer = clock.restart();
        deltaTime = deltaTimeTimer.asSeconds();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //Clear
        window.clear(sf::Color::White);

        //Update
        player.update(enemy1, deltaTime);
        player.update(enemy2, deltaTime);
        enemy1.update();
        enemy2.update();

        //Drawing
        player.draw(window, true);
        enemy1.draw(window, true);
        enemy2.draw(window, true);
        window.display();

        //FPS
        fps++;
        fpsTimeAccumulator += deltaTime;

        if (fpsTimeAccumulator >= 1.0f)
        {
            std::cout << "fps: " << fps << " ms: " << deltaTime * 1000 << std::endl;
            fps = 0;
            fpsTimeAccumulator = 0;
        }
    }
    return 0;
}