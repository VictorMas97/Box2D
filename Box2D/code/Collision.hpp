
/**
* @file Collision.hpp
* @author Victor Mas Toledo
* @date 10/04/2019
* @class Collision
* @brief Clase en donde se llaman a las colisiones de los objetos con otros
*/


#pragma once
#include <Box2D/Box2D.h>
#include <iostream>


namespace physics
{
	class Collison : public b2ContactListener
	{

	public:

		/**
		* @brief Se ejecuta cuando un objeto empieza a colisionar con otro
		* @param contact -> contiene toda la información de la colisión entre los objetos 
		*/

		void BeginContact(b2Contact* contact)
		{
			Box2DObject * firstObject = static_cast<Box2DObject *> (contact->GetFixtureA()->GetBody()->GetUserData());
			Box2DObject * secondObject = static_cast<Box2DObject *> (contact->GetFixtureB()->GetBody()->GetUserData());

			if (firstObject != nullptr && secondObject != nullptr)
			{
				if (firstObject->objectTag == "elevator" && secondObject->objectTag == "ball")
				{
					static_cast<b2PrismaticJoint *> (firstObject->joint)->EnableMotor(true);
				}

				else if (firstObject->objectTag == "fire" && secondObject->objectTag == "ball")
				{
					secondObject->SetReset(true);
				}
			}
		}

		/**
		* @brief Se ejecuta cuando un objeto termina de colisionar con otro
		* @param contact -> contiene toda la información de la colisión entre los objetos
		*/

		void EndContact(b2Contact* contact)
		{
			Box2DObject * firstObject = static_cast<Box2DObject *> (contact->GetFixtureA()->GetBody()->GetUserData());
			Box2DObject * secondObject = static_cast<Box2DObject *> (contact->GetFixtureB()->GetBody()->GetUserData());

			if (firstObject != nullptr && secondObject != nullptr)
			{
				if (firstObject->objectTag == "elevator" && secondObject->objectTag == "ball")
				{
					static_cast<b2PrismaticJoint *> (firstObject->joint)->EnableMotor(false);
				}
			}
		}
	};
}
