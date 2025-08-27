#include "Map.h"

#include <iostream>

Map::Map(MouseTile& mouseTile) : 
	m_mouseTile(mouseTile), m_mapSprites(nullptr)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
	m_mapSprites = new sf::Sprite[MAP_SIZE];
}

void Map::Load()
{
}

void Map::Update(double deltaTime, const sf::Vector2f& mousePosition)
{
    sf::Vector2f tilePosition;

    if (m_mouseTile.IsMouseClickedOnTile(tilePosition, mousePosition))
    {
        std::cout << "TILE POSITION: " << tilePosition.x << " " << tilePosition.y << std::endl;
    }
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < MAP_SIZE; i++)
	{
		window.draw(m_mapSprites[i]);
	}
}

