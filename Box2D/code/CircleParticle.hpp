#pragma once
#include "Particle.hpp"

namespace physics
{
	class CircleParticle : public Particle
	{
	public:
		CircleParticle();
		virtual void Render(sf::RenderWindow & window, bool active) override;
		virtual void Update(float delta_time) override;
	};
}