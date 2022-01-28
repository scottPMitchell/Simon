/// <summary>
/// @author Scott Mitchell
/// @date January 2022
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "Simon Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setUpButtons();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	//const int COL_1_LEFT = 
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	switch (m_gameMode)
	{
	case GameMode::Starting:
		break;
	case GameMode::Showing:
		break;
	case GameMode::Recieveing:
		break;
	case GameMode::GameOver:
		break;
	default:
		break;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(m_redSquare);
	m_window.draw(m_blueSquare);
	m_window.draw(m_greenSquare);
	m_window.draw(m_yellowSquare);
	m_window.draw(m_SimonIntroText);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_PixelFont.loadFromFile("ASSETS\\FONTS\\ARCADECLASSIC.TTF"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading font" << std::endl;
	}
	m_SimonIntroText.setFont(m_PixelFont);
	m_SimonIntroText.setString("Simon Game");
	m_SimonIntroText.setPosition(30.0f, 30.0f);
	m_SimonIntroText.setCharacterSize(60U);
	m_SimonIntroText.setOutlineColor(sf::Color::White);
	m_SimonIntroText.setFillColor(sf::Color::Black);
	m_SimonIntroText.setOutlineThickness(2.0f);
}

void Game::setUpButtons()
{
	m_redSquare.setFillColor(RED);
	m_redSquare.setSize(sf::Vector2f(200, 200));
	m_redSquare.setPosition(570.0f, 30.0f);
	m_blueSquare.setFillColor(BLUE);
	m_blueSquare.setSize(sf::Vector2f(200, 200));
	m_blueSquare.setPosition(570.0f, 250.0f);
	m_greenSquare.setFillColor(GREEN);
	m_greenSquare.setSize(sf::Vector2f(200, 200));
	m_greenSquare.setPosition(350.0f, 30.0f);
	m_yellowSquare.setFillColor(YELLOW);
	m_yellowSquare.setSize(sf::Vector2f(200, 200));
	m_yellowSquare.setPosition(350.0f, 250.0f);
}
