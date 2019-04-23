#pragma once
#include "CircleParticle.hpp"
#include <SFML/Graphics.hpp>

namespace physics
{
	template<typename PARTICLE> 
	class ParticleSystem
	{
	public:

		ParticleSystem(){}
		ParticleSystem(int particleCount, PARTICLE * particle, float xMin, float xMax)
		{
			for (int i =  0; i < particleCount; i++)
			{				
				PARTICLE a{ *particle };
				a.position = sf::Vector2f{ xMin, xMax };
				particles.push_back(a);//, sf::Vector2f{ xMin, xMax }
			
			}
		}

		void Render(sf::RenderWindow & window)
		{
			for (auto & particle : particles)
			{
				particle.Render(window);
			}
		}

		void Update(float delta_time)
		{
			for (auto & particle : particles)
			{
				particle.Update(delta_time);
			}
		}

		std::vector<PARTICLE> particles;
	};

	typedef ParticleSystem<CircleParticle> CircleParticleSystem;
	
}