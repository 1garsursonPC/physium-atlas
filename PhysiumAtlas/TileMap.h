#pragma once
#include <SFML/Graphics.hpp>
#include "logic/Hitbox.h"

#include <cmath>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool isColliding(Hitbox entity)
	{
		// Tout sauf 5
		// Taille bloc élémentaire 32x32
		unsigned offset_x = (unsigned)std::floor(entity.getPosition().getX() / 32);
		unsigned offset_y = (unsigned)std::floor(entity.getPosition().getY() / 32);
		unsigned size_x = (unsigned)std::ceil(entity.getSize().getX());
		unsigned size_y = (unsigned)std::ceil(entity.getSize().getX() / 32);
		for(unsigned i = offset_y; i <= size_y; i++)
			for (unsigned j = offset_x; j <= size_x; j++)
			{
				if (tiles[x + y*width] != 5)
					return true;
			}

		return false;
	}

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
	this->tiles = tiles;
	this->width = width;
	this->height = height;
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

    int* tiles;
    unsigned tiles_width;
    unsigned tiles_height;
};

