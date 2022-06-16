#include <SFML/Graphics.hpp>
<<<<<<< HEAD
=======
#include "TileMap.h"
#include "DrawableSprite.h"
>>>>>>> 5f198bdd20467db0a644ea0b6155b046ac59fe4e
#include "Player.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Player player = Player(0, Coordinates(64,500), Coordinates(22,44), 85);

    //Dessin du niveau
    const int level[] =
    {
       12, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,13,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 3, 7, 7, 7, 7,11, 5, 5, 5, 5, 5, 5, 5, 3, 7,11, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7,11, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7, 7, 7,11, 4,
       14, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,15,
    };

    //Creation de la Tilemap
    TileMap map;
    if (!map.load("../Sprites/Tilemap.png", sf::Vector2u(32, 32), level, 32, 18))
        return -1;

    Player player = Player(0, Coordinates(64, 500), Coordinates(22, 44), 85);

    //Ajout du Sprite du joueur
    DrawableSprite playerSprite;
    if (!playerSprite.load("../Sprites/Player.png"))
        return -1;
    playerSprite.new_pos(64, 500);

    //On fait tourner la boucle principale
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

        //On dessine le niveau
        window.clear();
        window.draw(map);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}
