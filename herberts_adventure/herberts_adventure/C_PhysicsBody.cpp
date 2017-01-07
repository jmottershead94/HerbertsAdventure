#include "C_PhysicsBody.h"

C_PhysicsBody::C_PhysicsBody()
{}

C_PhysicsBody::~C_PhysicsBody()
{}

void C_PhysicsBody::Init(const ObjectID id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	body_ = game_object.world()->CreateBody(id, game_object, mass, is_kinematic, density, friction, bounciness);
}

void C_PhysicsBody::Update(C_GameObject& game_object, float& dt)
{
	body_->Update(game_object, dt);
}