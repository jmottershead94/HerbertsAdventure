#ifndef  _C_NULLPHYSICSCOMPONENT_H_
#define  _C_NULLPHYSICSCOMPONENT_H_

#include "C_Rigidbody2DComponent.h"

class C_NullPhysicsComponent : public C_Rigidbody2DComponent
{
public:
	C_NullPhysicsComponent();
	~C_NullPhysicsComponent();
	virtual void Init(const ObjectID id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);
	virtual void Update(C_GameObject& game_object, float& dt);
};

#endif