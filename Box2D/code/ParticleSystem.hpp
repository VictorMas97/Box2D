
/**
* @file ParticleSystem.hpp
* @author Victor Mas Toledo
* @date 23/04/2019
* @class ParticleSystem
* @brief Clase que se encarga de montar el sistema de part�culas, renderizarlo y updatearlo
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
		* @param particleCount -> el n�mero de part�culas que va a tener el sistema de part�culas
		* @param lifeTime -> el tiempo de vida del sistema de part�culas
		* @param ParticleSystemPosition -> la posici�n del sistema de part�culas
		* @param xPositionOffset -> los offsets de la posici�n del eje X del sistema de part�culas
		* @param yPositionOffset -> los offsets de la posici�n del eje Y del sistema de part�culas
		* @param ParticleSystemVelocity -> la velocidad del sistema de part�culas
		* @param xVelocityOffset -> los offsets de la velocidad del eje X del sistema de part�culas
		* @param yVelocityOffset -> los offsets de la velocidad del eje Y del sistema de part�culas
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
		* @brief Renderiza el sistema de part�culas
		* @param window -> es la ventana en donde se tiene que renderizar la escena
		* @param ParticleSystemActive -> Si es "true" significa que el sistema de part�culas se debe renderizar
		*/

		void Render(sf::RenderWindow & window, bool ParticleSystemActive)
		{
			for (auto & particle : particles)
			{
				particle.Render(window, ParticleSystemActive);
			}
		}

		/**
		* @brief Atualiza el sistema de part�culas
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
		* @brief Calcula un n�mero aleatorio entre el rango de los par�metros y lo devuelve
		* @param a -> el n�mero m�nimo del rango
		* @param b -> el n�mero m�ximo del rango
		*/	

		float getRamdomFloat(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

		/**
		* @brief Un vector de todas las pert�culas que pertenecen al mismo sistema de part�culas
		*/	

		std::vector<PARTICLE> particles;
	};

	typedef ParticleSystem<CircleParticle> CircleParticleSystem;
	
}