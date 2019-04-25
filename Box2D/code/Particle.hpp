
/**
* @file Particle.hpp
* @author Victor Mas Toledo
* @date 22/04/2019
* @class Particle
* @brief Clase abstracta en donde se definen métodos y variables de una partícula
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace physics
{
	class Particle
	{
	public:

		/**
		* @brief Renderiza la partícula, es un método virtual
		* @param window -> es la ventana en donde se tiene que renderizar la patícula
		* @param active -> Si es "true" significa que la partícula se debe renderizar
		*/

		virtual void Render(sf::RenderWindow & window, bool active) = 0;

		/**
		* @brief Atualiza la partícula, es un método virtual
		* @param delta_time -> son los segundos por frame
		*/

		virtual void Update(float delta_time) = 0;

		/**
		* @brief Actúa de timer, y su valor inicial es 0
		*/	

		float startTime = 0;

		/**
		* @brief El tiempo de vida de la partícula
		*/	

		float lifeTime;

		/**
		* @brief La posición inicial de la partícula
		*/

		sf::Vector2f startPosition;

		/**
		* @brief La posición actual de la partícula
		*/

		sf::Vector2f position;

		/**
		* @brief La velocidad inicial y actual de la partícula
		*/

		sf::Vector2f velocity;

		/**
		* @brief Puntero a la forma gráfica de la partícula
		*/

		sf::Shape * shape;
	};
}
