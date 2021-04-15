#include "Bombs.h"
#include "TextureManager.h"
#include "Game.h"
#include "Explosion.h"
#include <random>
#include "MapTile.h"
///////////////////////////////////////////////////////////////
Bombs::Bombs() : ControllableElement(new BombsController)
{
	m_sprite.setTexture(*(TextureManager::Get("Bomb")));  
	m_sprite.setScale(40.f / 48.f, 40.f / 48.f);
}
///////////////////////////////////////////////////////////////
void Bombs::SetLocation(const LocalizationVector::Vector2e& location)
{
	ControllableElement::SetLocation(location);
	m_sprite.setPosition(location.x, location.y);
}
///////////////////////////////////////////////////////////////
void Bombs::Draw() 
{
	Game::Instance().GetWindow().draw(m_sprite);
}
///////////////////////////////////////////////////////////////
BombsController::BombsController() : m_time_to_explosion(2.f)
{
}
///////////////////////////////////////////////////////////////
void BombsController::Update(const float& deltaTime)
{
	m_time_to_explosion -= deltaTime;
	/*Generator losowego zasiêgu wybuchu bomb*/
	std::default_random_engine gen(std::clock());
	std::uniform_int_distribution<> dist(2,20);
	int range_of_explosion = dist(gen);
	/**/
	if (m_time_to_explosion <= 0)
	{
		m_owner->Destroy();   // Usuwa bombe

		/*Dodanie wybuchu w miejsce usunietej bomby*/
		auto* explosion_center = new Explosion();
		explosion_center->SetLocation(m_owner->GetLocation());
		Game::Instance().GetAllElements()->Add(explosion_center);

		
		/*Zmienne kontrolne sprawdzaj¹ce czy wybuch mo¿e sie rozprzesztrzeniaæ*/
		bool up_control = false;
		bool down_control = false;
		bool left_control = false;
		bool right_control = false;
	
		/*Pêtla wyœwietlaj¹ca wybuch*/

		///////////////////////////////////Up////////////////////////////////////
		int ite = 1;
		while (ite < range_of_explosion) 
		{
			
			auto* explosion_up = new Explosion();
			LocalizationVector::Vector2e temp = m_owner->GetLocation() + LocalizationVector::Vector2e(0, ite * 40);
			auto elementsInLocalization = Game::Instance().GetAllElements()->GetElementsLocalization(temp);
			
			if (up_control == false)
			{
				for (auto* element : elementsInLocalization)
				{
					auto* tile = dynamic_cast<MapTile*>(element);
					if (tile && tile->GetType() != TileType::Solid)
					{
						if (tile && tile->GetType() == TileType::Dectructable)
						{
							element->Destroy();
							explosion_up->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_up);
							up_control = true;
						}
						else {
							explosion_up->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_up);
						}
					}
					else { up_control = true; }
					
					
				}
			}
		
			/////////////////////////////////////Down/////////////////////////////////
		
			auto* explosion_down = new Explosion();
			temp = m_owner->GetLocation() + LocalizationVector::Vector2e(0, ite * -40);
			elementsInLocalization = Game::Instance().GetAllElements()->GetElementsLocalization(temp);

			if (down_control == false)
			{
				for (auto* element : elementsInLocalization)
				{
					auto* tile = dynamic_cast<MapTile*>(element);
					if (tile && tile->GetType() != TileType::Solid)
					{
						if (tile && tile->GetType() == TileType::Dectructable)
						{


							explosion_down->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_down);
							down_control = true;
						}
						else {
							explosion_down->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_down);
						}

					}
					else{ down_control = true; }
					
				}
			}
		
			/////////////////////////////////////Left///////////////////////////////////////

			auto* explosion_left = new Explosion();
			temp = m_owner->GetLocation() + LocalizationVector::Vector2e(ite * -40, 0);
			elementsInLocalization = Game::Instance().GetAllElements()->GetElementsLocalization(temp);
			if (left_control == false)
			{
				for (auto* element : elementsInLocalization)
				{

					auto* tile = dynamic_cast<MapTile*>(element);
					if (tile && tile->GetType() != TileType::Solid)
					{
						if (tile && tile->GetType() == TileType::Dectructable)
						{


							explosion_left->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_left);
							left_control = true;
						}
						else {
							explosion_left->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_left);
						}
					}
					else { left_control = true; }
				}
			}
			/////////////////////////////////////Right///////////////////////////////////////

			auto* explosion_right = new Explosion();
			temp = m_owner->GetLocation() + LocalizationVector::Vector2e(ite * 40, 0);
			elementsInLocalization = Game::Instance().GetAllElements()->GetElementsLocalization(temp);
			if (right_control == false)
			{
				for (auto* element : elementsInLocalization)
				{
					auto* tile = dynamic_cast<MapTile*>(element);
					if (tile && tile->GetType() != TileType::Solid)
					{
						if (tile && tile->GetType() == TileType::Dectructable)
						{


							explosion_right->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_right);
							right_control = true;
						}
						else {
							explosion_right->SetLocation(temp);
							Game::Instance().GetAllElements()->Add(explosion_right);
						}
					}
					else { right_control = true; }
				}
			}
			
			ite++;
		}
	}
}
