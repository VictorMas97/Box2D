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
		ParticleSystem(int particleCount, sf::Vector2f ParticleSystemPosition, float xMinOffset, float xMaxOffset)
		{
			srand(static_cast <unsigned> (time(0)));

			for (int i =  0; i < particleCount; i++)
			{				
				PARTICLE a{};
				std::cout << getRamdomFloat(xMinOffset, xMaxOffset) << std::endl;
				a.position = sf::Vector2f 
				{ 
					ParticleSystemPosition.x + getRamdomFloat(xMinOffset, xMaxOffset), 
					ParticleSystemPosition.y
				};
				particles.push_back(a);//, sf::Vector2f{ xMin, xMax }

				//particlePosX = rand() % 100;
				//particlePosY = rand() % 100;
				//a.position = sf::Vector2f{ particlePosX, particlePosY };
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
			std::cout << "hh";
		}

		std::vector<PARTICLE> particles;

		float getRamdomFloat(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}
	};

	typedef ParticleSystem<CircleParticle> CircleParticleSystem;
	
}