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

void C_World::ClearBodies()
{
	if (!bodies_.empty())
	{
		for (size_t i = 0; i < bodies_.size(); i++)
		{
			bodies_[i]->ResetCollisionProperties();
		}

		bodies_.clear();
	}
}

void C_World::CheckCollision(C_Body& bodyA, C_Body& bodyB)
{
	if (collider_manager_->IsColliding(bodyA, bodyB) == C_Collision2D::none)
	{
		bodyA.collision_flags_.push_back(false);
	}
	else
	{
		bodyA.colliding_bodies_.push_back(&bodyB);
		bodyA.collision_flags_.push_back(true);

		if (collider_manager_->IsColliding(bodyA, bodyB) == C_Collision2D::bottom)
		{
			/* If body A is NOT colliding with a trigger. */
			if (bodyB.id_ != ObjectID::trigger
				&& bodyB.id_ != ObjectID::endLevelTrigger)
			{
				/* If the body B is already on the ground or is static. */
				if (bodyB.velocity_.y == 0.0f || bodyB.on_ground_ || bodyB.is_kinematic_)
				{
					/* Body A now has something below. */
					bodyA.on_ground_ = true;
				}
			}
		}

		if (collider_manager_->IsColliding(bodyA, bodyB) == C_Collision2D::top)
		{
			bodyA.can_jump_ = false;
			//C_Debug::PrintToConsole("Should not be able to jump...");
		}

		if (collider_manager_->IsColliding(bodyA, bodyB) == C_Collision2D::right)
		{
		}

		if (collider_manager_->IsColliding(bodyA, bodyB) == C_Collision2D::left)
		{
		}
	}
}

void C_World::CheckBodyCollisions(C_Body& body)
{
	/* Reset collision properties because we are about to check them again. */
	body.ResetCollisionProperties();

	/* O(N^2) - Well this sucks... */
	for (std::vector<C_Body*>::iterator other_body = bodies_.begin(); other_body != bodies_.end(); other_body++)
	{
		/* IF THE IDS NOT ARE THE SAME. */
		if (body.id_ != (**other_body).id_)
		{
			/* CHECK COLLISIONS NORMALLY. */
			CheckCollision(body, (**other_body));
		}
	}
}

/* Thanks to Paul Firth: http://www.wildbunny.co.uk/blog/2011/04/06/physics-engines-for-dummies/ */
void C_World::ResolveCollision(C_Body& bodyA, C_Body& bodyB, float& dt)
{
	UNUSED(dt);

	sf::Vector2f relative_velocity = bodyB.velocity_ - bodyA.velocity_;
	sf::Vector2f velocity_normal = C_Utilities::Normalize(relative_velocity);
	float velocity_dot = C_Utilities::DotProduct(relative_velocity, velocity_normal);

	sf::Vector2f I = (((1.0f + bodyA.restitution_) * velocity_normal * velocity_dot) / (bodyA.inverse_mass_ + bodyB.inverse_mass_));
	
	bodyA.velocity_ += (I * bodyA.inverse_mass_);

	if (!bodyB.on_ground_)
	{
		bodyB.velocity_ -= (I * bodyB.inverse_mass_);
	}
}

void C_World::BodyCollisionResponse(C_Body& body, float& dt)
{
	/* If the body is not on the ground. */
	if (!body.on_ground_ && !body.is_kinematic_)
	{
		/* Apply gravity to the body. */
		body.ApplyForce(-gravity_, dt);
	}
	
	/* Looping through each of the collision flags. */
	for (std::vector<bool>::iterator collision = body.collision_flags_.begin(); collision != body.collision_flags_.end(); collision++)
	{
		/* If any of the collision flags are true. */
		if ((*collision))
		{
			/* The body has collided with something. */
			body.collided_ = true;
			break;
		}
	}

	/* TODO: Loop through colliding bodies and provide standard collision response. */
	/* Looping through each of the collisions. */
	for (std::vector<C_Body*>::iterator contact = body.colliding_bodies_.begin(); contact != body.colliding_bodies_.end(); contact++)
	{
		if (!body.is_kinematic_)
		{
			ResolveCollision(body, (**contact), dt);
		}
	}
}

void C_World::ProcessBodies(float& dt)
{
	/* Looping through all of the bodies. */
	if (!bodies_.empty())
	{
		for (size_t i = 0; i < bodies_.size(); i++)
		{
			/* Loop through each body in the world and check for collisions. */
			CheckBodyCollisions(*bodies_.at(i));

			/* Provide a response for any collisions. */
			BodyCollisionResponse(*bodies_.at(i), dt);
		}
	}
}

void C_World::Update(float& dt)
{
	ProcessBodies(dt);
}

C_Body* C_World::CreateBody(const ObjectID id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	/* Initialising a new body. */
	C_Body* new_body = new C_Body();
	new_body->Init(id, game_object, mass, is_kinematic, density, friction, bounciness);

	/* Add the body to our local vector for physics processing. */
	bodies_.push_back(new_body);

	/* Return the body for game object use. */
	return new_body;
}