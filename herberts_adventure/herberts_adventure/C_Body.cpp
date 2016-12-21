#include "C_Body.h"

C_Body::C_Body()
{}

C_Body::~C_Body()
{}

void C_Body::Init(C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	/* Initialising local attributes. */
	position_ = game_object.getPosition();
	rotation_ = game_object.getRotation();
	collider_ = game_object.getGlobalBounds();
	mass_ = mass;
	is_kinematic_ = is_kinematic;
	density_ = density;
	friction_ = friction;
	restitution_ = bounciness;
}

void C_Body::Update(C_GameObject & game_object)
{
	/* Updating the collider with the game object it is attached to. */
	game_object.setPosition(position_);
	game_object.setRotation(rotation_);
}