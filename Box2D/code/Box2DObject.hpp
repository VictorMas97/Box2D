#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace physics
{
	class Box2DObject
	{
	public:

		Box2DObject() {};

		Box2DObject(b2Vec2 objectPosition, b2World* box2DWorld, b2BodyType shapeType, sf::Color shapeColor, std::string tag, float radius);
		Box2DObject(b2Vec2 objectPosition, b2World* box2DWorld, b2BodyType shapeType, sf::Color shapeColor, std::string tag, std::vector<b2Vec2> polygonVertices);

		/** En Box2D las coordenadas Y crecen hacia arriba y en SFML crecen hacia abajo desde el borde superior.
		** Esta función se encarga de convertir el sistema de coordenadas para que la escena no se vea invertida.
		**/
		sf::Vector2f box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height);

		void Render(sf::RenderWindow & window);

		b2Shape * box2DShape;

		sf::Shape * graphicShape;

		b2Body * body;

		b2Joint * joint;

		b2Fixture * fixture;

		bool reset;

		std::string objectTag;

		void SetReset(bool restart)
		{
			reset = restart;
		}
	};
}


