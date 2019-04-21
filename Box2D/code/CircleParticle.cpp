#include "CircleParticle.hpp"

namespace physics
{
	CircleParticle::CircleParticle()
	{
		shape = new sf::CircleShape(3);
		shape->setPosition(sf::Vector2f(200.f, 500.f));
		shape->setFillColor(sf::Color::Red);
	}

	void CircleParticle::Render(sf::RenderWindow & window)
	{
		window.draw(*shape);
	}

	void CircleParticle::Update(float delta_time)
	{

	}
}