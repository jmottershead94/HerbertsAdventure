#include "C_Body.h"

C_Body::C_Body()
{}

C_Body::~C_Body()
{}

void C_Body::Init(const ObjectID id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	/* Initialising local attributes. */
	id_ = id;
	position_ = game_object.getPosition();
	rotation_ = game_object.getRotation();
	collider_ = game_object.getGlobalBounds();
	mass_ = mass;

	if (!is_kinematic)
	{
		inverse_mass_ = 1.0f / mass_;
	}
	else
	{
		inverse_mass_ = 0.0f;
	}

	is_kinematic_ = is_kinematic;
	density_ = density;
	friction_ = friction;
	restitution_ = bounciness;

	velocity_ = sf::Vector2f(0.0f, 0.0f);
}

void C_Body::ApplyForce(const sf::Vector2f force, float& dt)
{
	UNUSED(dt);

	/* Calculate the acceleration based on the force desired and the mass of the body. */
	sf::Vector2f a = force / inverse_mass_;
	
	/* Add on the acceleration value based on the force applied. */
	/* Delta time is applied to velocity in the main Update, so we don't need to apply it here too. */
	velocity_ += a;
}

void C_Body::ResetCollisionProperties()
{
	on_ground_ = false;
	can_jump_ = true;
	collided_ = false;
	colliding_left_ = false;
	colliding_top_ = false;
	colliding_right_ = false;
	colliding_bottom_ = false;

	if (!colliding_bodies_.empty())
	{
		colliding_bodies_.clear();
	}

	if (!collision_flags_.empty())
	{
		collision_flags_.clear();
	}

	if (!collisions_.empty())
	{
		collisions_.clear();
	}
}

void C_Body::CheckVelocityValue()
{
	if (C_Utilities::Abs(velocity_.x) > MAX_VELOCITY.x)
	{
		if(velocity_.x > 0.0f)
			velocity_.x = MAX_VELOCITY.x;
		else 
			velocity_.x = -MAX_VELOCITY.x;
	}

	/*if (C_Utilities::Abs(velocity_.y) > MAX_VELOCITY.y)
	{
		if (velocity_.y > 0.0f)
			velocity_.y = MAX_VELOCITY.y;
		else
			velocity_.y = -MAX_VELOCITY.y;
	}*/
}

void C_Body::Update(C_GameObject & game_object, float& dt)
{
	UNUSED(dt);

	CheckVelocityValue();

	if (velocity_ != sf::Vector2f(0.0f, 0.0f))
	{
		/* Updating the position of the collider. */
		position_ += (velocity_ * dt);
	}

	/* Updating the collider with the game object it is attached to. */
	game_object.setPosition(position_);
	game_object.setRotation(rotation_);
	collider_ = game_object.getGlobalBounds();
}