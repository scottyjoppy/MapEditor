#include <SFML/Graphics.hpp>
#include <iostream>

#include "Grid.h"
#include "MouseTile.h"

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Map Editor", sf::Style::Default, settings);
	window.setFramerateLimit(360);

	Grid grid
	(
	 	 // Grid Position
		 sf::Vector2f(0, 0), 
		 // Grid Size
		 sf::Vector2i(10, 6), 
		 // Cell Size
		 sf::Vector2i(16, 16), 
		 // Scale
		 sf::Vector2i(10, 10), 
		 sf::Color(255, 255, 255, 255),
		 // Line Thickness
		 2
	);
	MouseTile mouseTile
	(
		sf::Vector2i(16, 16), 
		sf::Vector2f(10, 10)
	);

	//-----INITIALIZE-----

	grid.Initialize();
	mouseTile.Initialize();

	//-----INITIALIZE-----
	
	//-----LOAD-----

	grid.Load();
	mouseTile.Load();

	//-----LOAD-----

	//-----GAME LOOP-----
	
	sf::Clock clock;

	while (window.isOpen())
	{	
		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		
		//-----UPDATE-----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		grid.Update(deltaTime);
		mouseTile.Update(deltaTime, mousePosition);

		//-----UPDATE-----
		
		//-----DRAW-----
		window.clear(sf::Color::Black);

		grid.Draw(window);
		mouseTile.Draw(window);

		window.display();
		//-----DRAW-----

	}

	return 0;
}

