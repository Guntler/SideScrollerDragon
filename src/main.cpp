#include "MediaManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	MediaManager mManager = MediaManager();

	int i = mManager.loadTexture("hitboxes.png");

	sf::Sprite sprite;
	sprite.setTexture(mManager.getTexture(i));

    RenderWindow window(VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}