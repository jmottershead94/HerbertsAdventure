#ifndef  _C_PHYSICSBODY_H_
#define  _C_PHYSICSBODY_H_

#include "C_Rigidbody2DComponent.h"

class C_PhysicsBody : public C_Rigidbody2DComponent
{
	public:
		C_PhysicsBody();
		~C_PhysicsBody();
		virtual void Init(const int id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);
		virtual void Update(C_GameObject& game_object, float& dt);
};

#endif