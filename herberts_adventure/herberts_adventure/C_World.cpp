#include "C_World.h"

C_World::C_World()
{}

C_World::~C_World()
{
	
}

void C_World::Init(const sf::Vector2f gravity)
{
	/* Initialising local attributes. */
	gravity_ = gravity;
}

void C_World::CleanUp()
{
	if (!bodies_.empty())
	{
		bodies_.clear();
	}
}

void C_World::ProcessBodies(float& dt)
{
	UNUSED(dt);

	//C_Debug::PrintToConsole("Updating bodies");

	/* O(N^2) - Well this sucks... */
	/* Looping through all of the bodies. */
	if (!bodies_.empty())
	{
		for (std::vector<C_Body*>::iterator body = bodies_.begin(); body != bodies_.end(); body++)
		{
			/* If the body is dynamic. */
			if (!(**body).is_kinematic_)
			{
				/* Loop through all of the bodies backwards. */
				for (std::vector<C_Body*>::iterator other_body = bodies_.begin(); other_body != bodies_.end(); other_body++)
				{
					/* If the body is not equal to the other body we are looking at. */
					if ((**body).id_ != (**other_body).id_)
					{
						/* If the current body is not colliding with anything else. */
						if ((**body).colliding_body_ == nullptr)
						{
							/* If the current body is not colliding with any of the other bodies. */
							if (!(**body).collider_.intersects((**other_body).collider_))
							{
								//std::cout << "Applying gravity!" << std::endl;
								//C_Debug::PrintToConsole("Applying gravity!");
								(**body).colliding_body_ = nullptr;

								/* Apply gravity to the body. */
								(**body).ApplyForce(-gravity_);
							}
							else
							{
								(**body).colliding_body_ = (*other_body);

								C_Debug::PrintToConsole("Collision!");
							}
						}
					}
				}
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