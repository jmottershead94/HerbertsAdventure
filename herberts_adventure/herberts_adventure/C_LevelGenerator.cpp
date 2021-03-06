#include "C_LevelGenerator.h"

C_LevelGenerator::C_LevelGenerator()
{}

C_LevelGenerator::~C_LevelGenerator()
{}

void C_LevelGenerator::Init(sf::RenderWindow* window, C_World * world, C_Camera* camera, int& level_number, Type level_type)
{
	/* Initialising local attributes. */
	window_ = window;
	world_ = world;
	camera_ = camera;
	ifstream_ = new std::ifstream();

	RestartLevel(level_number, level_type);
}

void C_LevelGenerator::RestartLevel(int& level_number, Type level_type)
{
	if(ifstream_->is_open())
	{
		ifstream_->close();
	}

	if (!objects_.empty())
	{
		objects_.clear();
	}

	world_->ClearBodies();

	/* Open the current level text file. */
	ifstream_->open("../assets/design/level_" + std::to_string(level_number) + ".txt");

	if (level_type == Type::forest)
	{
		CreateBackground("SPR_swamp.png");
	}
	else if (level_type == Type::desert)
	{
		CreateBackground("SPR_desert.png");
	}

	ReadTextFile();
}

void C_LevelGenerator::IncrementObjectWidth(float& width, int& text_file_width, int& map_x, char& file_char)
{
	// Increments the length of the object.
	width++;
	text_file_width += 128;

	// Sets the text file x coordinate in the correct position corresponding to the width of the object.
	map_x += text_file_width;
	ifstream_->get(file_char);
}

void C_LevelGenerator::ReadTextFile()
{
	char text_file_char;
	sf::Vector2i map_coordinates(0, 0);

	/* Error checking. */
	/* If the file stream doesn't exist OR cannot be read. */
	if (!ifstream_ || ifstream_->bad() || !ifstream_->is_open())
	{
		/* Exit the application. */
		C_Debug::PrintToConsole("ERROR: Level file could not be opened.");
		window_->close();
	}

	/* Keep looping until we have reached the end of the file. */
	while (!ifstream_->eof())
	{
		ifstream_->get(text_file_char);

		switch (text_file_char)
		{
			case ('.'):
			{
				break;
			}
			case ('#') :
			{
				float default_width = 1.0f;
				int original_map_x = map_coordinates.x;
				int text_file_width = 0;

				while (ifstream_->peek() == '#')
				{
					IncrementObjectWidth(default_width, text_file_width, map_coordinates.x, text_file_char);
				}

				CreateBox(ObjectID::dynamicObject, sf::Vector2f((float)original_map_x, (float)map_coordinates.y), sf::Vector2f(default_width, 1.0f));
				break;
			}
			case ('+') :
			{
				float default_width = 1.0f;
				int original_map_x = map_coordinates.x;
				int text_file_width = 0;

				while (ifstream_->peek() == '+')
				{
					IncrementObjectWidth(default_width, text_file_width, map_coordinates.x, text_file_char);
				}

				CreateBox(ObjectID::dynamicObjectStack, sf::Vector2f((float)original_map_x, (float)map_coordinates.y), sf::Vector2f(default_width, 1.0f));
				break;
			}
			case ('B') :
			{
				float default_width = 1.0f;
				int original_map_x = map_coordinates.x;
				int text_file_width = 0;

				while (ifstream_->peek() == 'B')
				{
					IncrementObjectWidth(default_width, text_file_width, map_coordinates.x, text_file_char);
				}

				CreateBouncingBox(ObjectID::dynamicObject, sf::Vector2f((float)original_map_x, (float)map_coordinates.y), sf::Vector2f(default_width, 1.0f));
				break;
			}
			case ('-') :
			{
				float default_width = 1.0f;
				int original_map_x = map_coordinates.x;
				int text_file_width = 0;

				while (ifstream_->peek() == '-')
				{
					IncrementObjectWidth(default_width, text_file_width, map_coordinates.x, text_file_char);
				}

				CreatePlatform(ObjectID::staticObject, sf::Vector2f((float)original_map_x, (float)map_coordinates.y), sf::Vector2f(default_width, 1.0f));
				break;
			}
			case ('C') :
			{
				float default_width = 1.0f;
				int original_map_x = map_coordinates.x;
				int text_file_width = 0;

				while (ifstream_->peek() == 'C')
				{
					IncrementObjectWidth(default_width, text_file_width, map_coordinates.x, text_file_char);
				}

				CreateCharacter(ObjectID::character, sf::Vector2f((float)original_map_x, (float)map_coordinates.y), sf::Vector2f(default_width, 1.0f));
				break;
			}
			case ('P') :
			{
				float default_width = 1.0f;
				int original_map_x = map_coordinates.x;
				int text_file_width = 0;

				while (ifstream_->peek() == 'P')
				{
					IncrementObjectWidth(default_width, text_file_width, map_coordinates.x, text_file_char);
				}

				CreatePlayer(ObjectID::playerOne, camera_, sf::Vector2f((float)original_map_x, (float)map_coordinates.y), sf::Vector2f(default_width, 1.0f));
				break;
			}
			case ('F') :
			{
				CreateFinishPoint(ObjectID::endLevelTrigger, sf::Vector2f((float)map_coordinates.x, (float)map_coordinates.y), sf::Vector2f(1.0f, 1.5f));
				break;
			}
			case ('\n') :
			{
				map_coordinates.y += 128;
				map_coordinates.x = 0;
				break;
			}
			default :
			{
				break;
			}
		};

		/* Move to the next text file character. */
		map_coordinates.x += 128;
	}
}

C_GameObject* C_LevelGenerator::CreateBackground(const std::string filename)
{
	bg_ = new C_GameObject();
	C_DemoInputComponent* input_component = new C_DemoInputComponent();
	C_NullPhysicsComponent* physics_component = new C_NullPhysicsComponent();

	bg_->Init(ObjectID::ui, world_, physics_component, input_component, filename, sf::Vector2f(0.0f, 0.0f), 0.0f, sf::Vector2f(1.0f, 1.0f));
	physics_component->Init(bg_->id(), *bg_, 0.0f, true, 0.0f, 0.0f, 0.0f);

	objects_.push_back(bg_);

	return bg_;
}

C_Player* C_LevelGenerator::CreatePlayer(const ObjectID id, C_Camera* camera, sf::Vector2f position, sf::Vector2f scale)
{
	C_Player* player = new C_Player();

	player->Init(id, world_, camera, "SPR_button.png", position, 0.0f, scale);

	objects_.push_back(player);

	return player;
}

C_Character* C_LevelGenerator::CreateCharacter(const ObjectID id, sf::Vector2f position, sf::Vector2f scale)
{
	C_Character* character = new C_Character();
	C_DemoInputComponent* input_component = new C_DemoInputComponent();
	
	character->Init(id, world_, input_component, "SPR_button.png", position, 0.0f, scale);

	objects_.push_back(character);

	return character;
}

C_GameObject* C_LevelGenerator::CreateBox(const ObjectID id, sf::Vector2f position, sf::Vector2f scale)
{
	C_GameObject* game_object = new C_GameObject();
	C_DemoInputComponent* input_component = new C_DemoInputComponent();
	C_PhysicsBody* physics_component = new C_PhysicsBody();

	game_object->Init(id, world_, physics_component, input_component, "SPR_button.png", position, 0.0f, scale);
	physics_component->Init(id, *game_object, 1.0f, false, 1.0f, 0.3f, 0.3f);

	objects_.push_back(game_object);

	return game_object;
}

C_GameObject* C_LevelGenerator::CreateBouncingBox(const ObjectID id, sf::Vector2f position, sf::Vector2f scale)
{
	C_GameObject* game_object = new C_GameObject();
	C_DemoInputComponent* input_component = new C_DemoInputComponent();
	C_PhysicsBody* physics_component = new C_PhysicsBody();

	game_object->Init(id, world_, physics_component, input_component, "SPR_button.png", position, 0.0f, scale);
	physics_component->Init(id, *game_object, 1.0f, false, 1.0f, 0.3f, 1.0f);

	objects_.push_back(game_object);

	return game_object;
}

C_GameObject* C_LevelGenerator::CreateFinishPoint(const ObjectID id, sf::Vector2f position, sf::Vector2f scale)
{
	C_GameObject* game_object = new C_GameObject();
	C_DemoInputComponent* input_component = new C_DemoInputComponent();
	C_PhysicsBody* physics_component = new C_PhysicsBody();

	game_object->Init(id, world_, physics_component, input_component, "SPR_bubble.png", position, 0.0f, scale);
	physics_component->Init(id, *game_object, 1.0f, true, 1.0f, 0.3f, 0.3f);

	objects_.push_back(game_object);

	return game_object;
}

C_GameObject* C_LevelGenerator::CreatePlatform(const ObjectID id, sf::Vector2f position, sf::Vector2f scale)
{
	C_GameObject* game_object = new C_GameObject();
	C_DemoInputComponent* input_component = new C_DemoInputComponent();
	C_PhysicsBody* physics_component = new C_PhysicsBody();

	game_object->Init(id, world_, physics_component, input_component, "SPR_button.png", position, 0.0f, scale);
	physics_component->Init(id, *game_object, 1.0f, true, 1.0f, 0.3f, 0.3f);

	objects_.push_back(game_object);

	return game_object;
}