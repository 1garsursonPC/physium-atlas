#pragma once
#include <SFML/Graphics.hpp>
#include "logic/Hitbox.h"
#include <iostream>
#include <cmath>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	std::string isColliding(Hitbox entity)
	{
		// Tout sauf 5
		// Taille bloc élémentaire 32x32
        int offset_x = (int)std::round((entity.getPosition().getX()) / 32);
        int offset_y = (int)std::floor((entity.getPosition().getY() + entity.getSize().getY()) / 32);

        std::string temp = "";

        if (tiles[offset_x + (32 * (offset_y - 1))] == 9)
            temp+= "Plafond;";
        if (tiles[offset_x + (32 * (offset_y))] == 1)
            temp += "Sol;";
        if (tiles[offset_x + (32 * (offset_y-1))] != 5 && tiles[offset_x + (32 * (offset_y - 1))] != 9)
            temp += "Deplacement;";
        if (tiles[offset_x + (32 * (offset_y))] == 5)
            temp += "Coll;";
       
        return temp;
	}

    std::string DirCollide(Hitbox entity)
    {
        int varX[] = { std::floor(entity.getPosition().getX() / 32), std::ceil(entity.getPosition().getX() / 32), std::round(entity.getPosition().getX() / 32) };

        if (varX[2] == varX[0])
            return "Gauche";
        else if (varX[2] == varX[1])
            return "Droite";
        return "None";
    }

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
	this->tiles = tiles;
	this->tiles_width = width;
	this->tiles_height = height;
        //Chargement du Tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    const int* tiles;
    unsigned tiles_width;
    unsigned tiles_height;
};

