#include "Box2DObject.hpp"
#include <iostream>
 
namespace physics
{
	Box2DObject::Box2DObject(b2Vec2 objectPosition, b2World* box2DWorld, b2BodyType shapeType, sf::Color shapeColor, std::string tag, float radius)
	{
		// Se crea el body a partir de una definicion de sus caracteristicas:
		reset = false;
		b2BodyDef body_definition;
		body_definition.type = shapeType; // abstraer
		body_definition.position.Set(objectPosition.x, objectPosition.y);  // Posicion inicial absoluta del objeto
		body = box2DWorld->CreateBody(&body_definition);
		objectTag = tag;
		body->SetUserData(this);

		// Se añade una fixture al body:

		box2DShape = new b2CircleShape;
		b2CircleShape * circle = dynamic_cast<b2CircleShape *>(box2DShape);
		circle->m_radius = radius;

		graphicShape = new sf::CircleShape;
		sf::CircleShape * graphicCircle = dynamic_cast<sf::CircleShape *>(graphicShape);

		b2FixtureDef body_fixture;
		body_fixture.shape = circle;
		body_fixture.density = 1.00f;
		body_fixture.restitution = 0.75f;
		body_fixture.friction = 0.50f;

		body->CreateFixture(&body_fixture);

		graphicCircle->setFillColor(shapeColor);
		graphicCircle->setRadius(radius);
	}

	Box2DObject::Box2DObject(b2Vec2 objectPosition, b2World * box2DWorld, b2BodyType shapeType, sf::Color shapeColor, std::string tag, std::vector<b2Vec2> polygonVertices)
	{
		// Se crea el body a partir de una definicion de sus caracteristicas:
		reset = false;
		b2BodyDef body_definition;

		body_definition.type = shapeType; // abstraer
		body_definition.position.Set(objectPosition.x, objectPosition.y);   // Posicion inicial absoluta del objeto
		//body_definition.angle = 0.4f;
		body = box2DWorld->CreateBody(&body_definition);
		body->SetUserData(this);
		objectTag = tag;

		// Se añade una fixture al body:

		box2DShape = new b2PolygonShape;
		b2PolygonShape * polygon = dynamic_cast<b2PolygonShape *>(box2DShape);
		//polygon->SetAsBox(25.f, 25.f);
		polygon->Set(&polygonVertices[0], polygonVertices.size());   //polygonVertices->Length());

		graphicShape = new sf::ConvexShape;
		sf::ConvexShape * graphicPolygon = dynamic_cast<sf::ConvexShape *>(graphicShape);

		b2FixtureDef body_fixture;

		body_fixture.shape = polygon;
		body_fixture.density = 1.00f;
		body_fixture.restitution = 0.50f;
		body_fixture.friction = 0.50f;

		body->CreateFixture(&body_fixture);

		graphicPolygon->setFillColor(shapeColor);
	}

	sf::Vector2f Box2DObject::box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height)
	{
		return sf::Vector2f(box2d_position.x, window_height - box2d_position.y);
	}

	void Box2DObject::Render(sf::RenderWindow & window)
	{
		// Se cachea el alto de la ventana en una variable local:
		float window_height = (float)window.getSize().y;

		// Se obtiene el transform del body:
		const b2Transform & body_transform = body->GetTransform();

		// Se obtiene el tipo de forma de la fixture:
		b2Shape::Type shape_type = box2DShape->GetType();

		if (shape_type == b2Shape::Type::e_circle) 
		{
			b2CircleShape * circle = dynamic_cast<b2CircleShape *>(box2DShape);

			float  radius = circle->m_radius;
			b2Vec2 center = circle->m_p;

			sf::CircleShape * graphicCircleRender = dynamic_cast<sf::CircleShape *>(graphicShape);

			graphicCircleRender->setPosition(box2d_position_to_sfml_position(b2Mul(body_transform, center), window_height) - sf::Vector2f(radius, radius));

			window.draw(*graphicCircleRender);
		}

		else if (shape_type == b2Shape::e_polygon)
		{
			b2PolygonShape * polygon = dynamic_cast<b2PolygonShape *>(box2DShape);
			sf::ConvexShape * graphicPolygonRender = dynamic_cast<sf::ConvexShape *>(graphicShape);

			int number_of_vertices = polygon->GetVertexCount();

			graphicPolygonRender->setPointCount(number_of_vertices);

			for (int index = 0; index < number_of_vertices; index++)
			{
				graphicPolygonRender->setPoint
				(
					index,
					box2d_position_to_sfml_position(b2Mul(body_transform, polygon->GetVertex(index)), window_height)
				);
			}

			window.draw(*graphicPolygonRender);
		}		
	}
}