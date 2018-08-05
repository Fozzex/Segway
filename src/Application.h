#pragma once
#include <SFML\Graphics.hpp>
#include <string>

#include "Definitions.h"
#include "Segway.h"

class Application
{
public:

	Application(int width, int height, std::string title);
	~Application();

	void handleInput();
	void update();
	void render();

	sf::RenderWindow* getWnd() { return &m_Window; }

private:

	sf::RenderWindow m_Window;
	sf::ContextSettings m_Settings;

	Segway m_Segway = { m_Window };

};