#include "C_Collision2D.h"

C_Collision2D::C_Collision2D()
{}

C_Collision2D::~C_Collision2D()
{}

C_Collision2D::CollidedSide C_Collision2D::IsColliding(C_Body& objectA, C_Body& objectB)
{
	if (!objectA.collider().intersects(objectB.collider()))
	{
		return none;
	}

	if (C_Utilities::Abs(objectA.velocity().x) < C_Utilities::Abs(objectA.velocity().y))
	{
		if (objectA.velocity().y > 0.0f)
		{
			return bottom;
		}

		return top;
	}
	else
	{
		if (objectA.velocity().x > 0.0f)
		{
			return right;
		}

		return left;
	}
}