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

		Scene(b2Vec2 gravity = b2Vec2{ 0, -9.8f });

		~Scene();

		void Update(float delta_time);

		void Render(sf::RenderWindow & window);

		std::map<std::string, std::shared_ptr<Box2DObject>> sceneObjects;

		b2World * box2DWorld;

		CircleParticle particle;

		ParticleSystem particleSystem;
	};
}