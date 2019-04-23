#include "CircleParticle.hpp"

namespace physics
{
	CircleParticle::CircleParticle()
	{
		shape = new sf::CircleShape(5);
		//shape->setPosition(position);   //sf::Vector2f(400.f, 560.f)
		shape->setFillColor(sf::Color::Red);
	}

	void CircleParticle::Render(sf::RenderWindow & window)
	{
		window.draw(*shape);
	}

	void CircleParticle::Update(float delta_time)
	{
		shape->setPosition(position);
	}
}