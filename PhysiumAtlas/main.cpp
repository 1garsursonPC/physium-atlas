#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "DrawableSprite.h"
#include "Player.h"
#include <iostream>
#include "PhysicEngine.h"

int main()
{
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
        6, 5, 5, 5, 3, 7, 7, 7, 7,11, 5, 5, 5, 5, 3, 7, 7,11, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7, 7, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,11, 4,
        6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,11, 4,
       14, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,15,
    };

    PhysicEngine game;

    //Creation de la Tilemap
    TileMap map;
    if (!map.load("../Sprites/Tilemap.png", sf::Vector2u(32, 32), level, 32, 18))
        return -1;

    Player player = Player(0, Coordinates(64, 500), Coordinates(22, 44), 85);

    //Ajout du Sprite du Boutton
    DrawableSprite button;
    if (!button.load("../Sprites/Button.png"))
        return -1;
    button.new_pos(50, 50);
    sf::Font font;
    if (!font.loadFromFile("../Sprites/Physium.ttf"))
        return -1;

    sf::Text text;
    text.setFont(font);
    text.setString("Gravity");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(85, 60);

    //Ajout du Sprite du joueur
    DrawableSprite playerSprite;
    if (!playerSprite.load("../Sprites/Player_R.png"))
        return -1;
    playerSprite.new_pos(64, 500);

    int pos_x=0, pos_y=0;
    std::string Coll = "";
    std::vector<std::string> Collisions;

    //On fait tourner la boucle principale
    while (window.isOpen())
    {
        sf::Clock clock; // Starts the clock

        sf::Time elapsedTime = clock.getElapsedTime();
        
        int offset_x = (int)std::round((player.getHitbox().getPosition().getX()) / 32);
        int offset_y = (int)std::floor((player.getHitbox().getPosition().getY() + player.getHitbox().getSize().getY()) / 32);

        if ((pos_x != offset_x) || (pos_y != offset_y))
        {
            Coll = map.isColliding(player.getHitbox());
            Collisions.clear();
            int pos, begin = 0;
            do 
            {
                pos = Coll.find(';', begin);
                Collisions.push_back(Coll.substr(begin, pos - begin));
                begin = pos + 1;
            } while (pos != std::string::npos);
            pos_x = offset_x;
            pos_y = offset_y;
        }  
        if (std::find(Collisions.begin(), Collisions.end(), "Deplacement") != Collisions.end()) {
            player.setSpeed(Coordinates(0, 0));
            player.setAcceleration(Coordinates(0, 0));
        }
        if(std::find(Collisions.begin(), Collisions.end(), "Sol") != Collisions.end() || std::find(Collisions.begin(), Collisions.end(), "Plafond") != Collisions.end()){
            player.setSpeed(Coordinates(player.getSpeed().getX(), 0));
            player.setAcceleration(Coordinates(player.getAcceleration().getX(), 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (std::find(Collisions.begin(), Collisions.end(), "Deplacement") == Collisions.end() || (std::find(Collisions.begin(), Collisions.end(), "Deplacement") != Collisions.end() && map.DirCollide(player.getHitbox()) != "Droite")))
        {
            player.moveRight(elapsedTime.asSeconds() * 1000);
            if (std::find(Collisions.begin(), Collisions.end(), "Coll") != Collisions.end() && std::find(Collisions.begin(), Collisions.end(), "Plafond") == Collisions.end())
                game.applyWeight(player);
            if (game.getG() > 0) 
            {
                if (!playerSprite.load("../Sprites/Player_R.png"))
                    return -1;
            }
            else
            {
                if (!playerSprite.load("../Sprites/Player_Flip_R.png"))
                    return -1;
            }       
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (std::find(Collisions.begin(), Collisions.end(), "Deplacement") == Collisions.end() || (std::find(Collisions.begin(), Collisions.end(), "Deplacement") != Collisions.end() && map.DirCollide(player.getHitbox()) != "Gauche")))
        {
            player.moveLeft(elapsedTime.asSeconds() * 1000);
            if (std::find(Collisions.begin(), Collisions.end(), "Coll") != Collisions.end() && std::find(Collisions.begin(), Collisions.end(), "Plafond") == Collisions.end())
                game.applyWeight(player);

            if (game.getG() > 0)
            {
                if (!playerSprite.load("../Sprites/Player_L.png"))
                    return -1;
            }
            else
            {
                if (!playerSprite.load("../Sprites/Player_Flip_L.png"))
                    return -1;
            }
        }
        else if (std::find(Collisions.begin(), Collisions.end(), "Coll") != Collisions.end() && std::find(Collisions.begin(), Collisions.end(), "Plafond") == Collisions.end())
        {
            game.applyWeight(player);
        }
        else
        {
            player.idle(elapsedTime.asSeconds() * 1000);
            player.setSpeed(Coordinates(player.getSpeed().getX(), 0));
            player.setAcceleration(Coordinates(player.getAcceleration().getX(), 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (std::find(Collisions.begin(), Collisions.end(), "Coll") == Collisions.end() || std::find(Collisions.begin(), Collisions.end(), "Plafond") != Collisions.end()))
        {
            player.setSpeed(Coordinates(player.getSpeed().getX(), 0));
            player.setAcceleration(Coordinates(player.getAcceleration().getX(), 0));
            if (game.getG() < 0)
                player.jump(elapsedTime.asSeconds() * 1000, true);
            else if (game.getG() > 0)
                player.jump(elapsedTime.asSeconds() * 1000, false);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (event.mouseButton.x >= 50 && event.mouseButton.x <= 212 && event.mouseButton.y >= 50 && event.mouseButton.y <= 102)
                {
                    player.setSpeed(Coordinates(player.getSpeed().getX(), 0));
                    player.setAcceleration(Coordinates(player.getAcceleration().getX(), 0));
                    game.setG(-game.getG());
                    if (game.getG() < 0)
                    {
                        player.getHitbox().setPosition(Coordinates(player.getHitbox().getPosition().getX(), player.getHitbox().getPosition().getY() - 15));
                        if (!playerSprite.load("../Sprites/Player_Flip_R.png"))
                            return -1;
                    }
                    else if (game.getG() > 0)
                    {
                        player.getHitbox().setPosition(Coordinates(player.getHitbox().getPosition().getX(), player.getHitbox().getPosition().getY() + 15));
                        if (!playerSprite.load("../Sprites/Player_R.png"))
                            return -1;
                    }
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
            clock.restart(); // Restart the clock to know when was the last input
        }
        playerSprite.new_pos(player.getHitbox().getPosition().getX(), player.getHitbox().getPosition().getY());


        //On dessine le niveau
        window.clear();
        window.draw(map);
        window.draw(playerSprite);
        window.draw(button);
        window.draw(text);
        window.display();
    }

    return 0;
}
