#pragma once
#include <SFML/Graphics.hpp>

class MouseTile
{
	private:
		sf::Texture m_tileSheet;
		sf::Sprite m_tile;

        sf::Vector2f m_tilePosition;
        sf::Vector2i m_tileGridPosition;

		sf::Vector2i m_tileSize;
		sf::Vector2f m_tileScale;
		sf::Vector2f m_offset;

        bool m_isMouseOnGrid;
        int number;
        double keyCooldown;

	public:
		MouseTile
		(
			const sf::Vector2i& tileSize, 
			const sf::Vector2f& tileScale,
			const sf::Vector2f& offset
		);
		~MouseTile();

		void Initialize();
		void Load();
		void Update(double deltaTime, const sf::Vector2f& mousePosition);
		void Draw(sf::RenderWindow& window);

        bool IsMouseClickedOnTile
        (
             sf::Vector2f& tilePosition, 
             sf::Vector2i& gridPosition, 
             const sf::Vector2f& mousePosition
        ) const;

        inline const sf::Sprite& GetSprite() const { return m_tile; }
};	

