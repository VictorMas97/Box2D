
/**
* @file ParticleSystem.hpp
* @author Victor Mas Toledo
* @date 23/04/2019
* @class ParticleSystem
* @brief Clase que se encarga de montar el sistema de partículas, renderizarlo y updatearlo
*/

#pragma once
#include "CircleParticle.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <time.h>    

namespace physics
{
	template<typename PARTICLE> 
	class ParticleSystem
	{
	public:

		ParticleSystem(){}
		ParticleSystem(int particleCount, sf::Vector2f lifeTime, sf::Vector2f ParticleSystemPosition, sf::Vector2f xPositionOffset, sf::Vector2f yPositionOffset,
	                                                             sf::Vector2f ParticleSystemVelocity, sf::Vector2f xVelocityOffset, sf::Vector2f yVelocityOffset)
		{
			srand(static_cast <unsigned> (time(0)));

			for (int i =  0; i < particleCount; i++)
			{				
				PARTICLE particle{};

				particle.startPosition = particle.position = sf::Vector2f
				{ 
					ParticleSystemPosition.x + getRamdomFloat(xPositionOffset.x, xPositionOffset.y),
					ParticleSystemPosition.y + getRamdomFloat(yPositionOffset.x, yPositionOffset.y)
				};

				particle.velocity = sf::Vector2f
				{
					ParticleSystemVelocity.x + getRamdomFloat(xVelocityOffset.x, xVelocityOffset.y),
					ParticleSystemVelocity.y + getRamdomFloat(yVelocityOffset.x, yVelocityOffset.y)
				};

				particle.lifeTime = getRamdomFloat(lifeTime.x, lifeTime.y);

				particles.push_back(particle);
			}
		}

		void Render(sf::RenderWindow & window, bool ParticleSystemActive)
		{
			for (auto & particle : particles)
			{
				particle.Render(window, ParticleSystemActive);
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

		float getRamdomFloat(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}
	};

	typedef ParticleSystem<CircleParticle> CircleParticleSystem;
	
}