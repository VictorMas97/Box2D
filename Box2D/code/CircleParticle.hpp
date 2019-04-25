
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
		CircleParticle();
		virtual void Render(sf::RenderWindow & window, bool active) override;
		virtual void Update(float delta_time) override;
	};
}