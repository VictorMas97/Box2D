#pragma once
#include <Box2D/Box2D.h>
#include <iostream>


namespace physics
{
	class Collison : public b2ContactListener
	{

	public:
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
					std::cout << "hola";
					secondObject->SetReset(true);
					//secondObject->body->SetTransform({ 50.f, 200.f }, 0.f);
				}
			}
		}

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
