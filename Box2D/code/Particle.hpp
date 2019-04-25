
/**
* @file Particle.hpp
* @author Victor Mas Toledo
* @date 22/04/2019
* @class Particle
* @brief Clase abstracta en donde se definen m�todos y variables de una part�cula
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace physics
{
	class Particle
	{
	public:

		/**
		* @brief Renderiza la part�cula, es un m�todo virtual
		* @param window -> es la ventana en donde se tiene que renderizar la pat�cula
		* @param active -> Si es "true" significa que la part�cula se debe renderizar
		*/

		virtual void Render(sf::RenderWindow & window, bool active) = 0;

		/**
		* @brief Atualiza la part�cula, es un m�todo virtual
		* @param delta_time -> son los segundos por frame
		*/

		virtual void Update(float delta_time) = 0;

		/**
		* @brief Act�a de timer, y su valor inicial es 0
		*/	

		float startTime = 0;

		/**
		* @brief El tiempo de vida de la part�cula
		*/	

		float lifeTime;

		/**
		* @brief La posici�n inicial de la part�cula
		*/

		sf::Vector2f startPosition;

		/**
		* @brief La posici�n actual de la part�cula
		*/

		sf::Vector2f position;

		/**
		* @brief La velocidad inicial y actual de la part�cula
		*/

		sf::Vector2f velocity;

		/**
		* @brief Puntero a la forma gr�fica de la part�cula
		*/

		sf::Shape * shape;
	};
}
