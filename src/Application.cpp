#include "Application.h"

Application::Application(int width, int height, std::string title)
{
	m_Settings.antialiasingLevel = 4;
	m_Window.create(sf::VideoMode(width, height), title, sf::Style::Close, m_Settings);
}

Application::~Application()
{

}

void Application::handleInput()
{
	sf::Event evnt;
	while (m_Window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			m_Window.close();
			break;
		}
		m_Segway.handleInput(evnt);
	}
}

void Application::update()
{
	m_Window.setFramerateLimit(FPS_CAP);
	m_Segway.update();
}

void Application::render()
{
	m_Window.clear({ 30, 100, 30 });
	m_Segway.render();
	m_Window.display();
}