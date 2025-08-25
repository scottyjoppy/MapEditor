#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile
(
	const sf::Vector2i& tileSize, 
	const sf::Vector2f& tileScale,
	const sf::Vector2f& offset
) :
	m_tileSize(tileSize), 
	m_tileScale(tileScale),
	m_offset(offset)
{
}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load()
{
	m_tileSheet.loadFromFile("assets/world/ground tileset/tileset_road.png");
	m_tile.setTexture(m_tileSheet);
	m_tile.setTextureRect(sf::IntRect(0 * m_tileSize.x, 0, m_tileSize.x, m_tileSize.y));
	m_tile.setScale(m_tileScale);
}

void MouseTile::Update(double deltaTime, sf::Vector2f mousePosition, void (*OnGridClick)(int))
{
	int gridIndexX = (mousePosition.x - m_offset.x) / (m_tileSize.x * m_tileScale.x);
	int x = gridIndexX * (m_tileSize.x * m_tileScale.x) + m_offset.x;
	int gridIndexY = (mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);
	int y = gridIndexY * (m_tileSize.y * m_tileScale.y) + m_offset.y;

	m_tile.setPosition(sf::Vector2f(x, y));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int index = gridIndexX + gridIndexY * 10;
		std::cout << index << std::endl;
		OnGridClick(index);
	}
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}
