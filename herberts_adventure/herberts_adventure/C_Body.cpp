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
	inverse_mass_ = 1.0f / mass_;
	is_kinematic_ = is_kinematic;
	density_ = density;
	friction_ = friction;
	restitution_ = bounciness;
}

void C_Body::ApplyForce(const sf::Vector2f force, float& dt)
{
	velocity_ = sf::Vector2f(0.0f, 0.0f);
	translation_ = sf::Vector2f(0.0f, 0.0f);

	/* Calculate the acceleration based on the force desired and the mass of the body. */
	sf::Vector2f a = force / inverse_mass_;
	//sf::Vector2f a = force / mass_;

	/* Calculate the difference in the velocity. */
	sf::Vector2f dv = a;
	velocity_ += dv;

	/* Calculate the difference in the position. */
	sf::Vector2f ds = velocity_;
	translation_ += ds;

	position_ += (translation_ * dt);
}

void C_Body::ResetCollisionProperties()
{
	on_ground_ = false;
	can_jump_ = true;
	collided_ = false;
	colliding_bodies_.clear();
	collision_flags_.clear();
}

void C_Body::Update(C_GameObject & game_object)
{
	/* Updating the collider with the game object it is attached to. */
	game_object.setPosition(position_);
	game_object.setRotation(rotation_);
	collider_ = game_object.getGlobalBounds();
}