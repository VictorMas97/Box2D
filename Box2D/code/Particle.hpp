#pragma once
#include <SFML/Graphics.hpp>

namespace physics
{
	class Particle
	{
	public:

		//Particle() {};

		virtual void Render(sf::RenderWindow & window, bool active) = 0;
		virtual void Update(float delta_time) = 0;

		float startTime = 0;

		float lifeTime;

		sf::Vector2f startPosition;

		sf::Vector2f position;

		sf::Vector2f velocity;

		sf::Shape * shape;
	};
}
