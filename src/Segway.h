#pragma once
#include <SFML\Graphics.hpp>
#include <algorithm>
#include <iostream>

#include "Definitions.h"

class Segway
{
public:

	Segway(sf::RenderWindow& wnd, sf::Vector2i pos = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
	~Segway();

	void handleInput(sf::Event evnt);
	void update();
	void render();

private:

	sf::RenderWindow* m_WndPtr;

	sf::RectangleShape m_Body;
	sf::Texture m_Texture;
	sf::Vector2f m_Direction, m_Velocity;

	float m_fAngle = 0.0f;
	float m_Speed = 0.0f;

};