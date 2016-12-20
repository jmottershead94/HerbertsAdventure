#include "C_PhysicsBody.h"

C_PhysicsBody::C_PhysicsBody()
{}

C_PhysicsBody::~C_PhysicsBody()
{}

void C_PhysicsBody::Init(C_GameObject& game_object, const bool is_kinematic, const float density, const float friction, const float bounciness)
{
	/* If the body is kinematic. */
	if (is_kinematic)
	{
		/* Set the body to be static. */
		body_def_.type = b2_staticBody;
	}
	/* Otherwise, the body is not kinematic. */
	else
	{
		/* Set the body to be dynamic. */
		body_def_.type = b2_dynamicBody;
	}

	//float32 x = game_object.getPosition().x;
	//float32 y = game_object.getPosition().y;
	//float32 angle = C_Utilities::DegToRad(game_object.getRotation());

	//body_def_.position.Set(x, y);
	//body_def_.angle = angle;
	body_ = game_object.world()->CreateBody(&body_def_);
	body_->SetTransform(b2Vec2(game_object.getPosition().x, game_object.getPosition().y), C_Utilities::DegToRad(game_object.getRotation()));

	shape_.SetAsBox(game_object.getScale().x * BOX2D_FRAMEWORK_SIZE_OFFSET, game_object.getScale().y * BOX2D_FRAMEWORK_SIZE_OFFSET);

	fixture_def_.shape = &shape_;

	if (is_kinematic)
	{
		fixture_def_.density = density;
		fixture_def_.friction = friction;
		fixture_def_.restitution = bounciness;
		body_->CreateFixture(&fixture_def_);
	}
	else
	{
		body_->CreateFixture(&shape_, 0.0f);
	}

	body_->SetUserData(&game_object);
}

void C_PhysicsBody::Update(C_GameObject& game_object)
{
	b2Vec2 position = body_->GetPosition();
	float32 rotation = body_->GetAngle();
	game_object.setPosition(position.x, position.y);
	game_object.setRotation(C_Utilities::RadToDeg(rotation));

	//std::cout << "Position X: " << game_object.getPosition().x << std::endl;
	//std::cout << "Position Y: " << game_object.getPosition().y << std::endl;	
}