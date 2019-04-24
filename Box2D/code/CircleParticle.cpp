#include "CircleParticle.hpp"

namespace physics
{
	CircleParticle::CircleParticle()
	{
		shape = new sf::CircleShape(3);
		shape->setFillColor(sf::Color::Red);
	}

	void CircleParticle::Render(sf::RenderWindow & window, bool active)
	{
		if (active)
		{
			window.draw(*shape);
		}
	}

	void CircleParticle::Update(float delta_time)
	{
		startTime += delta_time;

		if (startTime >= lifeTime)
		{
			startTime = 0;
			position = startPosition;
		}

		position += velocity;
		shape->setPosition(position);
	}
}