#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "DrawableSprite.h"
#include "Player.h"
#include <iostream>
#include "PhysicEngine.h"

int main()
{
    //Creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(1024, 576), "Tilemap");

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

    PhysicEngine game;

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

        sf::Time elapsedTime = clock.getElapsedTime();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.moveRight(elapsedTime.asSeconds() * 1000);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.moveLeft(elapsedTime.asSeconds() * 1000);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            player.jump(elapsedTime.asSeconds() * 1000);
        }
        else 
        {
            player.idle(elapsedTime.asSeconds() * 1000);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            clock.restart(); // Restart the clock to know when was the last input
        }
        game.applyWeight(player);

        playerSprite.new_pos(player.getHitbox().getPosition().getX(), player.getHitbox().getPosition().getY());

        //std::cout << "Position : " << player.getHitbox().getPosition().getX() << std::endl;
        //std::cout << "Vitesse : " << player.getSpeed().getX() << std::endl;
        //std::cout << "Accélération : " << player.getAcceleration().getX() << std::endl;
        //std::cout << std::endl;


        //On dessine le niveau
        window.clear();
        window.draw(map);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}