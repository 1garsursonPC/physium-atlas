#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DrawableSprite : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& sprite)
    {
        //Chargement de l'image
        if (!m_sprite.loadFromFile(sprite))
            return false;
        return true;
    }

    void new_pos(int x, int y);

private:
    sf::Sprite *sprite = new sf::Sprite;
    sf::Texture m_sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sprite->setTexture(m_sprite);
        states.transform *= getTransform();

        target.draw(*sprite, states);
    }
};

