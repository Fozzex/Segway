#include "Segway.h"

Segway::Segway(sf::RenderWindow& wnd, sf::Vector2i pos) :
	m_WndPtr(&wnd)
{
	m_Body.setSize({SEGWAY_WIDTH, SEGWAY_HEIGHT});
	m_Body.setOrigin(SEGWAY_WIDTH / 2, SEGWAY_HEIGHT / 2);
	m_Body.setPosition(sf::Vector2f(pos));
	
	m_Texture.loadFromFile(SEGWAY_TEXTURE_PATH);
	m_Body.setTexture(&m_Texture);
}

Segway::~Segway()
{

}

void Segway::handleInput(sf::Event evnt)
{
	switch (evnt.type)
	{
	default:
		break;
	}
}

void Segway::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_fAngle += SEGWAY_TURN_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_fAngle -= SEGWAY_TURN_SPEED;
	}

	if (m_fAngle > 360)
		m_fAngle = 1 + (m_fAngle - 360);
	if (m_fAngle < 1)
		m_fAngle = 360 - (1 - m_fAngle);

	m_Direction.x = cosf(-m_fAngle * (PI / 180));
	m_Direction.y = sinf(-m_fAngle * (PI / 180));

	if (m_Speed > SEGWAY_FRICTION)
		m_Speed -= SEGWAY_FRICTION;
	else if (m_Speed < -SEGWAY_FRICTION)
		m_Speed += SEGWAY_FRICTION;
	else
		m_Speed = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Speed += SEGWAY_ACCEL_SPEED;

		if (m_Speed > SEGWAY_MOVE_SPEED)
			m_Speed = SEGWAY_MOVE_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Speed -= SEGWAY_ACCEL_SPEED;

		if (m_Speed < -SEGWAY_MOVE_SPEED)
			m_Speed = -SEGWAY_MOVE_SPEED;
	}

	m_Velocity = m_Direction * m_Speed;
	m_Body.move(m_Velocity);
	m_Body.setRotation((360 - m_fAngle) + 90);
}

void Segway::render()
{
	m_WndPtr->draw(m_Body);
}