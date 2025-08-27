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
	m_offset(offset),
    m_isMouseOnGrid(false)
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

void MouseTile::Update(double deltaTime, const sf::Vector2f& mousePosition)
{
    m_tileGridPosition.x = (mousePosition.x - m_offset.x) / (m_tileSize.x * m_tileScale.x);
    m_tileGridPosition.y = (mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);

    m_tilePosition.x = m_tileGridPosition.x * (m_tileSize.x * m_tileScale.x) + m_offset.x;
    m_tilePosition.y = m_tileGridPosition.y * (m_tileSize.y * m_tileScale.y) + m_offset.y;

    m_tile.setPosition(m_tilePosition);
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}

bool MouseTile::IsMouseClickedOnTile(sf::Vector2f& tilePosition, const sf::Vector2f& mousePosition) const 
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        tilePosition = m_tilePosition; 
        return true;
    }
    return false;
}
