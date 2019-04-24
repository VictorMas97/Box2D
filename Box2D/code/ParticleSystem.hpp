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
		ParticleSystem(int particleCount, sf::Vector2f ParticleSystemPosition, float xMinOffset, float xMaxOffset, float yMinOffset, float yMaxOffset,
	      sf::Vector2f ParticleSystemVelocity, float xMinOffsetVelocity, float xMaxOffsetVelocity, float yMinOffsetVelocity, float yMaxOffsetVelocity)
		{
			srand(static_cast <unsigned> (time(0)));

			for (int i =  0; i < particleCount; i++)
			{				
				PARTICLE particle{};
				std::cout << getRamdomFloat(xMinOffset, xMaxOffset) << std::endl;
				particle.position = sf::Vector2f 
				{ 
					ParticleSystemPosition.x + getRamdomFloat(xMinOffset, xMaxOffset), 
					ParticleSystemPosition.y + getRamdomFloat(yMinOffset, yMaxOffset)
				};

				particle.velocity = sf::Vector2f
				{
					ParticleSystemVelocity.x + getRamdomFloat(xMinOffsetVelocity, xMaxOffsetVelocity),
					ParticleSystemVelocity.y + getRamdomFloat(yMinOffsetVelocity, yMaxOffsetVelocity)
				};
				particles.push_back(particle);
			}
			std::cout << particles.size() << std::endl;
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
			//std::cout << "hh";
		}

		std::vector<PARTICLE> particles;

		float getRamdomFloat(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}
	};

	typedef ParticleSystem<CircleParticle> CircleParticleSystem;
	
}