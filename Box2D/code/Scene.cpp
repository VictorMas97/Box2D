#include "Scene.hpp"
#include "Collision.hpp"


namespace physics
{
	Scene::Scene(b2Vec2 gravity)
	{
		box2DWorld = new b2World(gravity);

		Collison * myContactListenerInstance = new Collison{};
		box2DWorld->SetContactListener(myContactListenerInstance);

		std::vector <b2Vec2> lowFloor1 = 
		{
			{0, 0},
			{0, 100},
			{100, 100},
			{200, 30},
		    {200, 0}
		};

		std::vector <b2Vec2> lowFloor2 =
		{
			{0, 0},
			{0, 30},
			{400, 30},
			{400, 0}
		};

		std::vector <b2Vec2> lowFloorPlatform =
		{
			{0, 0},
			{0, 30},
			{200, 30},
			{200, 0}
		};

		std::vector <b2Vec2> middleFloor1 =
		{
			{0, 0},
			{0, 30},
			{100, 30},
			{100, 0}
		};

		std::vector <b2Vec2> middleFloor2 =
		{
			{0, 0},
			{200, 130},
			{200, 100},
			{0, -30}
		};

		std::vector <b2Vec2> middleFloor3 =
		{
			{0, 0},
			{0, 30},
			{100, 30},
			{100, 0}
		};

		std::vector <b2Vec2> middleFloorPlatform =
		{
			{0, 0},
			{0, 30},
			{100, 30},
			{100, 0}
		};

		std::vector <b2Vec2> finishPlatform1 =
		{
			{0, 0},
			{0, 10},
			{50, 50},
			{50, 40}
		};

		std::vector <b2Vec2> finishPlatform2 =
		{
			{0, 0},
			{0, 10},
			{50, -30},
			{50, -40}
		};

		//sceneObjects["ball"] = std::make_shared<Box2DObject>(b2Vec2{ 700.f, 40.f }, box2DWorld, b2_dynamicBody, sf::Color::Yellow, "ball", 10.f);
		sceneObjects["ball"] = std::make_shared<Box2DObject>(b2Vec2{ 150.f, 300.f }, box2DWorld, b2_dynamicBody, sf::Color::Yellow, "ball", 10.f);

		sceneObjects["lowFloor1"] = std::make_shared<Box2DObject>(b2Vec2{ 0.f, 0.f }, box2DWorld, b2_staticBody, sf::Color::Blue, "lowFloor1", lowFloor1);
		sceneObjects["lowFloor2"] = std::make_shared<Box2DObject>(b2Vec2{ 200.f, 0.f }, box2DWorld, b2_staticBody, sf::Color::Blue, "lowFloor2", lowFloor2);

		sceneObjects["lowFloorPlatform"] = std::make_shared<Box2DObject>(b2Vec2{ 600.f, 0.f }, box2DWorld, b2_dynamicBody, sf::Color::Green, "elevator", lowFloorPlatform);

		sceneObjects["middleFloor1"] = std::make_shared<Box2DObject>(b2Vec2{ 500.f, 400.f }, box2DWorld, b2_staticBody, sf::Color::Blue, "middleFloor1", middleFloor1);
		sceneObjects["middleFloor2"] = std::make_shared<Box2DObject>(b2Vec2{ 300.f, 300.f }, box2DWorld, b2_staticBody, sf::Color::Blue, "middleFloor2", middleFloor2);
		sceneObjects["middleFloor3"] = std::make_shared<Box2DObject>(b2Vec2{ 200.f, 270.f }, box2DWorld, b2_staticBody, sf::Color::Blue, "middleFloor3", middleFloor3);

		sceneObjects["middleFloorPlatform"] = std::make_shared<Box2DObject>(b2Vec2{ 100.f, 270.f }, box2DWorld, b2_dynamicBody, sf::Color::Green, "elevator", middleFloorPlatform);

		sceneObjects["finishPlatform1"] = std::make_shared<Box2DObject>(b2Vec2{ 50.f, 400.f }, box2DWorld, b2_staticBody, sf::Color::Red, "finishPlatform1", finishPlatform1);
		sceneObjects["finishPlatform2"] = std::make_shared<Box2DObject>(b2Vec2{ 0.f, 440.f }, box2DWorld, b2_staticBody, sf::Color::Red, "finishPlatform2", finishPlatform2);


		b2PrismaticJointDef prismaticJointDef;
		prismaticJointDef.bodyA = sceneObjects["lowFloor2"]->body;
		prismaticJointDef.bodyB = sceneObjects["lowFloorPlatform"]->body;
		prismaticJointDef.collideConnected = false;
		prismaticJointDef.enableMotor = false;
		prismaticJointDef.motorSpeed = 50.f;
		prismaticJointDef.maxMotorForce = 500000.f;
		prismaticJointDef.enableLimit = true;
		prismaticJointDef.lowerTranslation = 0.f;
		prismaticJointDef.upperTranslation = 400.f;
		prismaticJointDef.localAxisA.Set(0.f, 1.f);
		prismaticJointDef.localAnchorA.Set(401.f, 0.f);
		prismaticJointDef.localAnchorB.Set(0.f, 0.f);


		b2PrismaticJoint* prismaticJoint = (b2PrismaticJoint*)box2DWorld->CreateJoint(&prismaticJointDef);

		sceneObjects["lowFloorPlatform"]->joint = prismaticJoint;


		b2PrismaticJointDef prismaticJointDef2;
		prismaticJointDef2.bodyA = sceneObjects["middleFloor3"]->body;
		prismaticJointDef2.bodyB = sceneObjects["middleFloorPlatform"]->body;
		prismaticJointDef2.collideConnected = false;
		prismaticJointDef2.enableMotor = false;
		prismaticJointDef2.motorSpeed = 50.f;
		prismaticJointDef2.maxMotorForce = 500000.f;
		prismaticJointDef2.enableLimit = true;
		prismaticJointDef2.lowerTranslation = 0.f;
		prismaticJointDef2.upperTranslation = 150.f;
		prismaticJointDef2.localAxisA.Set(0.f, 1.f);
		prismaticJointDef2.localAnchorA.Set(-100.f, 0.f);
		prismaticJointDef2.localAnchorB.Set(0.f, 0.f);

		b2PrismaticJoint* prismaticJoint2 = (b2PrismaticJoint*)box2DWorld->CreateJoint(&prismaticJointDef2);

		sceneObjects["middleFloorPlatform"]->joint = prismaticJoint2;
	}

	Scene::~Scene()
	{
		delete box2DWorld;
	}

	void Scene::Update(float delta_time)
	{
		box2DWorld->Step(delta_time, 8, 4);
	}

	void Scene::Render(sf::RenderWindow & window)
	{
		for (std::map<std::string, std::shared_ptr<Box2DObject>>::iterator it = sceneObjects.begin(); it != sceneObjects.end(); ++it)
		{
			it->second->Render(window);
			//std::cout << it->first << " => " << it->second << std::endl;
		}
	}
}

