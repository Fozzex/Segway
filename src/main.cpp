#include "Application.h"
#include "Definitions.h"

int main()
{
	Application app(WINDOW_WIDTH, WINDOW_HEIGHT, "Segway");

	while (app.getWnd()->isOpen())
	{
		app.handleInput();
		app.update();
		app.render();
	}
}