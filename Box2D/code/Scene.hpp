
/**
* @file Scene.hpp
* @author Victor Mas Toledo
* @date 28/03/2019
* @class Scene
* @brief Clase que se encarga de montar la escena, renderizarla y updatearla
*/

#pragma once
#include "Box2DObject.hpp"
#include "CircleParticle.hpp"
#include "ParticleSystem.hpp"
#include "Collision.hpp"
#include <Box2D/Box2D.h>
#include <vector>

namespace physics
{
	class Scene
	{

	public:

		/**
		* @brief Constructor de la escena
		* @param gravity -> gravedad del mundo, por defecto es de -9.8 en el eje Y
		*/	

		Scene(b2Vec2 gravity = b2Vec2{ 0, -9.8f });

		/**
		* @brief Desontructor de la escena
		*/	

		~Scene();

		/**
		* @brief Atualiza la escena
		* @param delta_time -> son los segundos por frame
		*/	

		void Update(float delta_time);

		/**
		* @brief Renderiza la escena
		* @param window -> es la ventana en donde se tiene que renderizar la escena 
		*/	

		void Render(sf::RenderWindow & window);

		/**
		* @brief Contine todos los "Box2DObject" de la escena
		*/	

		std::map<std::string, std::shared_ptr<Box2DObject>> sceneObjects;

		/**
		* @brief Un puntero al mundo
		*/	

		b2World * box2DWorld;

		/**
		* @brief Sistema del partículas de partículas redondas
		*/	

		CircleParticleSystem particleSystem;

		/**
		* @brief Puntero al "Box2DObject" de la escena cuyo tag es "ball"
		*/	

		std::shared_ptr<Box2DObject> ball;

		/**
		* @brief Si es "true" significa que la "ball" se debe resetear
		*/	

		bool particleSystemActive;
	};
}