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
			//std::cout << "colision" << std::endl;
			Box2DObject * firstObject = static_cast<Box2DObject *> (contact->GetFixtureA()->GetBody()->GetUserData());
			Box2DObject * secondObject = static_cast<Box2DObject *> (contact->GetFixtureB()->GetBody()->GetUserData());

			if (firstObject != nullptr && secondObject != nullptr)
			{
				if (firstObject->objectTag == "elevator" && secondObject->objectTag == "ball")
				{
					//std::cout << firstObject->box2DShape->m_type << std::endl;

					static_cast<b2PrismaticJoint *> (firstObject->joint)->EnableMotor(true);
				}
			}
		}

		void EndContact(b2Contact* contact)
		{
			//std::cout << "colision" << std::endl;
			Box2DObject * firstObject = static_cast<Box2DObject *> (contact->GetFixtureA()->GetBody()->GetUserData());
			Box2DObject * secondObject = static_cast<Box2DObject *> (contact->GetFixtureB()->GetBody()->GetUserData());

			if (firstObject != nullptr && secondObject != nullptr)
			{
				if (firstObject->objectTag == "elevator" && secondObject->objectTag == "ball")
				{
					//std::cout << firstObject->box2DShape->m_type << std::endl;

					static_cast<b2PrismaticJoint *> (firstObject->joint)->EnableMotor(false);
				}
			}
		}
	};
}
