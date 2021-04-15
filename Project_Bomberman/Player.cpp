#include "Player.h"
#include "Game.h"
#include "TextureManager.h"
#include "Bombs.h"
Player::Player(int PlayerNumber) : ControllableElement(new PlayerController(PlayerNumber)) 
{
	m_sprite.setTexture(*(TextureManager::Get("Bomberman_Front")));
	m_sprite.setScale(2.f / 3.f, 2.f / 3.f);
	m_sprite.setOrigin(32, 91);
}
///////////////////////////////////////////////////////////////
void Player::SetDirection(PlayerDirection direction)
{
	if (m_direction != direction)
	{
		m_direction = direction;
		switch (m_direction)
		{
		case Up:
			m_sprite.setTexture(*(TextureManager::Get("Bomberman_Back")));
			break;
		case Down:
			m_sprite.setTexture(*(TextureManager::Get("Bomberman_Front")));
			break;
		case Left:
			m_sprite.setTexture(*(TextureManager::Get("Bomberman_Side")));
			m_sprite.setScale(-2.f / 3.f, 2.f / 3.f);
			break;
		case Right:
			m_sprite.setTexture(*(TextureManager::Get("Bomberman_Side")));
			m_sprite.setScale(2.f / 3.f, 2.f / 3.f);
			break;

		}
	}
}
///////////////////////////////////////////////////////////////
bool Player::IsColliding()
{
	sf::FloatRect collider(sf::Vector2f(m_location.x - 15, m_location.y - 10),sf::Vector2f(30,30));
	auto tiles = Game::Instance().GetAllElements()->GetColidingTiles();
	for (auto* tile : tiles)
	{
		LocalizationVector::Vector2e temp = tile->GetLocation();
		sf::FloatRect tileCollider(sf::Vector2f(temp.x, temp.y), sf::Vector2f(40, 40));
		if (tileCollider.intersects(collider))
		{
			return true;
		}
	}
	return false;
}
///////////////////////////////////////////////////////////////
void Player::SetLocation(const LocalizationVector::Vector2e& location)
{
	ControllableElement::SetLocation(location);
	m_sprite.setPosition(location.x, location.y);
}
///////////////////////////////////////////////////////////////
void Player::SetLifeNumber(const int &lifenumber)
{
	ControllableElement::SetLifeNumber(lifenumber);
}
///////////////////////////////////////////////////////////////
void Player::Draw()
{
	Game::Instance().GetWindow().draw(m_sprite);
}
///////////////////////////////////////////////////////////////
bool PlayerController::MoveUp(const float& delta)
{
	auto* owner = dynamic_cast<Player*>(m_owner);

	m_owner->Move(LocalizationVector::Vector2e(0,delta));
	owner->SetDirection(Up);

	if (owner->IsColliding())
	{
		m_owner->Move(LocalizationVector::Vector2e(0, -delta));
	}
	return false;
}
///////////////////////////////////////////////////////////////
bool PlayerController::MoveDown(const float& delta)
{
	auto* owner = dynamic_cast<Player*>(m_owner);
	m_owner->Move(LocalizationVector::Vector2e(0,delta));
	owner->SetDirection(Down);
	if (owner->IsColliding())
	{
		m_owner->Move(LocalizationVector::Vector2e(0, -delta));
	}
	return false;
}
///////////////////////////////////////////////////////////////
bool PlayerController::MoveLeft(const float& delta)
{
	
	auto* owner = dynamic_cast<Player*>(m_owner);
	m_owner->Move(LocalizationVector::Vector2e(delta, 0));
	owner->SetDirection(Left);
	if (owner->IsColliding())
	{
		m_owner->Move(LocalizationVector::Vector2e(-delta, 0));
	}
	return false;
}
///////////////////////////////////////////////////////////////
bool PlayerController::MoveRight(const float& delta)
{
	auto* owner = dynamic_cast<Player*>(m_owner);
	m_owner->Move(LocalizationVector::Vector2e(delta, 0));
	owner->SetDirection(Right);
	if (owner->IsColliding())
	{
		m_owner->Move(LocalizationVector::Vector2e(-delta, 0));
	}

	return false;
}
///////////////////////////////////////////////////////////////
PlayerController::PlayerController(int playernumber) : m_moveSpeed(250), m_player_number(playernumber), m_min_time_bomb(1.1f), m_bomb_time(0.5f)
{
}
///////////////////////////////////////////////////////////////
void PlayerController::Update(const float& deltaTime)
{
	
	
	auto* owner = dynamic_cast<Player*>(m_owner);

	m_bomb_time -= deltaTime;

	switch (m_player_number) {
	case 1:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->MoveUp(-m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->MoveLeft(-m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->MoveDown(m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->MoveRight(m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_bomb_time <= 0 )
		{
			m_bomb_time = m_min_time_bomb;
			auto* bomb = new Bombs();

			LocalizationVector::Vector2e temp = m_owner->GetLocation();
			temp.x = (int(temp.x) / 40) * 40;
			temp.y = (int(temp.y) / 40) * 40;


			bomb->SetLocation(temp);
			Game::Instance().GetAllElements()->Add(bomb);
		}
		break;
	case 2:

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->MoveUp(-m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->MoveLeft(-m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->MoveDown(m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->MoveRight(m_moveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_bomb_time <= 0)
		{
			m_bomb_time = m_min_time_bomb;
			auto* bomb = new Bombs();

			LocalizationVector::Vector2e temp = m_owner->GetLocation();
			temp.x = (int(temp.x) / 40) * 40;
			temp.y = (int(temp.y) / 40) * 40;


			bomb->SetLocation(temp);
			Game::Instance().GetAllElements()->Add(bomb);
		}
		break;
	}
}
