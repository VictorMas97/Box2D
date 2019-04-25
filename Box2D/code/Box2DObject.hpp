
/**
* @file Box2DObject.hpp
* @author Victor Mas Toledo
* @date 10/03/2019
* @class Box2DObject
* @brief Clase en donde se construye y renderiza el objeto Box2D combinado con el objeto SFML, para proporcionarle un color
*/

#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace physics
{
	class Box2DObject
	{
	public:

		/**
		* @brief Constructor por defecto de Box2DObject
		*/	

		Box2DObject() {};

		/**
		* @brief Constructor alternativo de Box2DObject que sirve para contruir Box2DObject cuya forma sea una circumferencia
		* @param objectPosition -> la posición del objeto
		* @param box2DWorld -> el mundo al que pertenece el objeto
		* @param shapeType -> el tipo de forma del objeto
		* @param shapeColor -> el color de la forma del objeto
		* @param tag -> el tag del objeto
		* @param radius -> el radio de la circumferencia
		*/

		Box2DObject(b2Vec2 objectPosition, b2World* box2DWorld, b2BodyType shapeType, sf::Color shapeColor, std::string tag, float radius);

		/**
		* @brief Contructor alternativo de Box2DObject que sirve para contruir Box2DObject cuya forma sea un poligono
		* @param objectPosition -> la posición del objeto
		* @param box2DWorld -> el mundo al que pertenece el objeto
		* @param shapeType -> el tipo de forma del objeto
		* @param shapeColor -> el color de la forma del objeto
		* @param tag -> el tag del objeto
		* @param polygonVertices -> los vertices del poligono
		*/	

		Box2DObject(b2Vec2 objectPosition, b2World* box2DWorld, b2BodyType shapeType, sf::Color shapeColor, std::string tag, std::vector<b2Vec2> polygonVertices);

		/**
		* @brief Se encarga de convertir el sistema de coordenadas para que la escena no se vea invertida.
		* @param box2d_position -> la posición del "Box2DObject"
		* @param window_height -> la altura de la ventana
		*/	

		sf::Vector2f box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height);

		/**
		* @brief Renderiza la escena
		* @param window -> es la ventana en donde se tiene que renderizar el Box2DObject
		*/	

		void Render(sf::RenderWindow & window);

		/**
		* @brief Actualiza la variabla "reset" con la información del parametro
		* @param restart -> si es "true" significa que el "Box2DObject" se debe resetear
		*/	

		void SetReset(bool restart)
		{
			reset = restart;
		}

		/**
		* @brief Puntero a la forma fí­sica del "Box2DObject"
		*/	

		b2Shape * box2DShape;

		/**
		* @brief Puntero a la forma gráfica del "Box2DObject"
		*/	

		sf::Shape * graphicShape;

		/**
		* @brief Puntero al body del "Box2DObject"
		*/	

		b2Body * body;

		/**
		* @brief Puntero al joint de Box2D
		*/	

		b2Joint * joint;

		/**
		* @brief Puntero a la fixture del "Box2DObject"
		*/	

		b2Fixture * fixture;

		/**
		* @brief Si es "true" significa que el "Box2DObject" se debe resetear
		*/	

		bool reset;

		/**
		* @brief Contine el tag del "Box2DObject"
		*/	

		std::string objectTag;
	};
}


