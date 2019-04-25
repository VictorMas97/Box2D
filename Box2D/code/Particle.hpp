
/**
* @file Particle.hpp
* @author Victor Mas Toledo
* @date 22/04/2019
* @class Particle
* @brief Clase abstracta en donde se definen métodos y variables de una partícula
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace physics
{
	class Particle
	{
	public:

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
