/*

	Rigidbody 2D Component Class
	============================

	Created:	20th December 2016
	Filter:		Components/Physics
	Class Name:	C_Rigidbody2DComponent
	Base Class: N/A
	Author:		Jason Mottershead

	Purpose:	Rigidbody2D will provide objects with a rigidbody to interact with
				the physics engine. This will be the base class for static and
				dynamic body components.

*/

/* Header guard. */
#ifndef  _C_RIGIDBODY2D_H_
#define  _C_RIGIDBODY2D_H_

/* Include header files here. */
/* Application. */
#include "C_GameObject.h"
#include "box2D_conversions.h"

class C_GameObject;

/* Input component is just a standard class. */
class C_Rigidbody2DComponent
{
	public:
		virtual ~C_Rigidbody2DComponent();
		virtual void Init(C_GameObject& game_object, const bool is_kinematic, const float density, const float friction, const float bounciness) = 0;
		virtual void Update(C_GameObject& game_object) = 0;

		/* Getters. */
		inline b2Body* body() { return body_; }

	protected:
		/* Attributes. */
		b2BodyDef body_def_;
		b2Body* body_;
		b2PolygonShape shape_;
		b2FixtureDef fixture_def_;
};

#endif