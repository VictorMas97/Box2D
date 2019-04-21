#pragma once
#include <SFML/Graphics.hpp>

namespace physics
{
	class Particle
	{
	public:

		Particle() {};

		virtual void Render(sf::RenderWindow & window) = 0;
		virtual void Update(float delta_time) = 0;

		sf::Vector2f position;

		sf::Vector2f velocity;

		sf::Shape * shape;
	};
}
