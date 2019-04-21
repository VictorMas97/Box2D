#include "ParticleSystem.hpp"

namespace physics
{
	void physics::ParticleSystem::Render(sf::RenderWindow & window)
	{
		circleParticle->Render(window);
	}

	void physics::ParticleSystem::Update(float delta_time)
	{
		circleParticle->Update(delta_time);
	}
}