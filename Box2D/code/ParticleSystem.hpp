#pragma once
#include "CircleParticle.hpp"
#include <SFML/Graphics.hpp>

namespace physics
{
	class ParticleSystem
	{
	public:

		void Render(sf::RenderWindow & window);
		void Update(float delta_time);

		std::vector<Particle> particles;

		CircleParticle * circleParticle;
	};
}