
/**
* @file CircleParticle.hpp
* @author Victor Mas Toledo
* @date 22/04/2019
* @class CircleParticle
* @brief Clase en donde se renderizan y updatean las partícular con forma redondeada, hereda de la clase "Particle"
*/

#pragma once
#include "Particle.hpp"

namespace physics
{
	class CircleParticle : public Particle
	{
	public:

		/**
		* @brief Constructor por defecto de ParticleSystem
		*/

		CircleParticle();

		/**
		* @brief Renderiza la patícula con forma circular
		* @param window -> es la ventana en donde se tiene que renderizar la patícula con forma circular
		* @param active -> Si es "true" significa que la partícula con forma circular se debe renderizar
		*/

		virtual void Render(sf::RenderWindow & window, bool active) override;

		/**
		* @brief Atualiza la partícula con forma circular
		* @param delta_time -> son los segundos por frame
		*/

		virtual void Update(float delta_time) override;
	};
}