
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
		
		/**
		* @brief Constructor por defecto de ParticleSystem
		*/

		ParticleSystem(){}

		/**
		* @brief Renderiza la escena
		* @param particleCount -> el número de partículas que va a tener el sistema de partículas
		* @param lifeTime -> el tiempo de vida del sistema de partículas
		* @param ParticleSystemPosition -> la posición del sistema de partículas
		* @param xPositionOffset -> los offsets de la posición del eje X del sistema de partículas
		* @param yPositionOffset -> los offsets de la posición del eje Y del sistema de partículas
		* @param ParticleSystemVelocity -> la velocidad del sistema de partículas
		* @param xVelocityOffset -> los offsets de la velocidad del eje X del sistema de partículas
		* @param yVelocityOffset -> los offsets de la velocidad del eje Y del sistema de partículas
		*/

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

		/**
		* @brief Renderiza el sistema de partículas
		* @param window -> es la ventana en donde se tiene que renderizar la escena
		* @param ParticleSystemActive -> Si es "true" significa que el sistema de partículas se debe renderizar
		*/

		void Render(sf::RenderWindow & window, bool ParticleSystemActive)
		{
			for (auto & particle : particles)
			{
				particle.Render(window, ParticleSystemActive);
			}
		}

		/**
		* @brief Atualiza el sistema de partículas
		* @param delta_time -> son los segundos por frame
		*/

		void Update(float delta_time)
		{
			for (auto & particle : particles)
			{
				particle.Update(delta_time);
			}
		}

		/**
		* @brief Calcula un número aleatorio entre el rango de los parámetros y lo devuelve
		* @param a -> el número mínimo del rango
		* @param b -> el número máximo del rango
		*/	

		float getRamdomFloat(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

		/**
		* @brief Un vector de todas las pertículas que pertenecen al mismo sistema de partículas
		*/	

		std::vector<PARTICLE> particles;
	};

	typedef ParticleSystem<CircleParticle> CircleParticleSystem;
	
}