#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Player player = Player(0, Coordinates(64,500), Coordinates(22,44), 85);

    while (window.isOpen())
    {
        sf::Clock clock; // Starts the clock

        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Time elapsedTime = clock.getElapsedTime();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player.moveRight(elapsedTime.asSeconds()*1000);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            {
                player.moveLeft(elapsedTime.asSeconds()*1000);
            }

            if (event.type == sf::Event::Closed)
                window.close();
  
            clock.restart(); // Restart the clock to know when was the last input
        }
        player.idle();

        std::cout << "Position : " << player.getHitbox().getPosition().getX() << std::endl;
        std::cout << "Vitesse : " << player.getSpeed().getX() << std::endl;
        std::cout << "Accélération : " << player.getAcceleration().getX() << std::endl;
        std::cout << std::endl;
   

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}