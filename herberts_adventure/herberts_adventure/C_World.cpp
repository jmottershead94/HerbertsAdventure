#include "C_World.h"

C_World::C_World()
{}

C_World::~C_World()
{}

void C_World::Init(const sf::Vector2f gravity)
{
	/* Initialising local attributes. */
	gravity_ = gravity;
	collider_manager_ = new C_Collision2D();
}

void C_World::CleanUp()
{
	if (!bodies_.empty())
	{
		bodies_.clear();
	}
}

void C_World::CheckBodyCollisions(C_Body& body)
{
	/* O(N^2) - Well this sucks... */
	/* Loop through all of the bodies backwards. */
	for (std::vector<C_Body*>::iterator other_body = bodies_.begin(); other_body != bodies_.end(); other_body++)
	{
		/* If the body is not equal to the other body we are looking at. */
		if (body.id_ != (**other_body).id_)
		{
			if (collider_manager_->IsColliding(body, (**other_body)) == C_Collision2D::none)
			{
				body.on_ground_ = false;
				body.collided_ = false;
			}
			else
			{
				body.colliding_body_ = (*other_body);
				body.collided_ = true;

				if (collider_manager_->IsColliding(body, (**other_body)) == C_Collision2D::bottom)
				{
					body.on_ground_ = true;
				}
				else if (collider_manager_->IsColliding(body, (**other_body)) == C_Collision2D::top)
				{}
				else if (collider_manager_->IsColliding(body, (**other_body)) == C_Collision2D::right)
				{}
				else if (collider_manager_->IsColliding(body, (**other_body)) == C_Collision2D::left)
				{}
			}
		}
	}
}

void C_World::BodyCollisionResponse(C_Body& body, float& dt)
{
	if (!body.on_ground_)
	{
		body.ApplyForce(-gravity_, dt);
	}
}

void C_World::ProcessBodies(float& dt)
{
	UNUSED(dt);

	/* Looping through all of the bodies. */
	if (!bodies_.empty())
	{
		for (std::vector<C_Body*>::iterator body = bodies_.begin(); body != bodies_.end(); body++)
		{
			/* If the body is dynamic. */
			if (!(**body).is_kinematic_)
			{
				/* Loop through each body in the world and check for collisions. */
				CheckBodyCollisions((**body));

				/* Provide a response for any collisions. */
				BodyCollisionResponse((**body), dt);
			}
		}
	}
}

void C_World::Update(float& dt)
{
	ProcessBodies(dt);
}

C_Body * C_World::CreateBody(const int id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	/* Initialising a new body. */
	C_Body* new_body = new C_Body();
	new_body->Init(id, game_object, mass, is_kinematic, density, friction, bounciness);

	/* Add the body to our local vector for physics processing. */
	bodies_.push_back(new_body);

	/* Return the body for game object use. */
	return new_body;
}