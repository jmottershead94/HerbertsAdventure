#include "C_NullPhysicsComponent.h"

C_NullPhysicsComponent::C_NullPhysicsComponent()
{}

C_NullPhysicsComponent::~C_NullPhysicsComponent()
{}

void C_NullPhysicsComponent::Init(C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	UNUSED(game_object);
	UNUSED(mass);
	UNUSED(is_kinematic);
	UNUSED(density);
	UNUSED(friction);
	UNUSED(bounciness);
}

void C_NullPhysicsComponent::Update(C_GameObject& game_object, float& dt)
{
	UNUSED(dt);
	UNUSED(game_object);
}