/// <summary>
/// author Scott Mitchell January 2022
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setUpButtons();

	sf::RenderWindow m_window; // main SFML window

	sf::Color RED{ 180, 0, 0, 225 };

	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	
	sf::RectangleShape m_redSquare;

	bool m_exitGame; // control exiting game 

};

#endif // !GAME_HPP

