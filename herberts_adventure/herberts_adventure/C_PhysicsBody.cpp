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

	body_ = game_object.world()->CreateBody(&body_def_);
	body_->SetTransform(b2Vec2(FRAMEWORK_BOX2D_POS_X(game_object.getPosition().x + FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().width * 0.5f)), FRAMEWORK_BOX2D_POS_Y(game_object.getPosition().y) + FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().height * 0.5f)), C_Utilities::DegToRad(game_object.getRotation()));
	
	std::cout << "Position X: " << FRAMEWORK_BOX2D_POS_X(game_object.getPosition().x) + FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().width * 0.5f) << std::endl;
	std::cout << "Position Y: " << FRAMEWORK_BOX2D_POS_Y(game_object.getPosition().y) + FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().height * 0.5f) << std::endl;

	shape_.SetAsBox(FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().width) * BOX2D_FRAMEWORK_SIZE_OFFSET, FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().height) * BOX2D_FRAMEWORK_SIZE_OFFSET);
	
	std::cout << "Size X: " << FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().width) * BOX2D_FRAMEWORK_SIZE_OFFSET << std::endl;
	std::cout << "Size Y: " << FRAMEWORK_BOX2D_SIZE(game_object.getGlobalBounds().height) * BOX2D_FRAMEWORK_SIZE_OFFSET << std::endl;

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

void C_PhysicsBody::Update(C_GameObject& game_object, float& dt)
{
	UNUSED(dt);
	b2Vec2 position = body_->GetPosition();
	float32 rotation = body_->GetAngle();

	game_object.setPosition(sf::Vector2f(BOX2D_FRAMEWORK_POS_X(position.x), BOX2D_FRAMEWORK_POS_Y(position.y)));
	game_object.setRotation(C_Utilities::RadToDeg(rotation));

	//std::cout << "Position X: " << game_object.getPosition().x << std::endl;
	//std::cout << "Position Y: " << game_object.getPosition().y << std::endl;	
}