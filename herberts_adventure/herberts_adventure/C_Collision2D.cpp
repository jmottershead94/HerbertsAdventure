#include "C_Collision2D.h"

C_Collision2D::C_Collision2D()
{}

C_Collision2D::~C_Collision2D()
{}

C_Collision2D::CollidedSide C_Collision2D::IsColliding(C_Body& game_object, C_Body& other_game_object)
{
	if (!game_object.collider().intersects(other_game_object.collider()))
	{
		return none;
	}

	if (C_Utilities::Abs(game_object.velocity().x) < C_Utilities::Abs(game_object.velocity().y))
	{
		if (game_object.velocity().y > 0.0f)
		{
			return bottom;
		}

		return top;
	}
	else
	{
		if (game_object.velocity().x > 0.0f)
		{
			return right;
		}

		return left;
	}
}