#include "Explosion.h"
#include "TextureManager.h"
#include "Game.h"
#include "Bombs.h"
#include "MapTile.h"
#include "Player.h"
#include <sstream>
#include "Bomberman_main.h"
///////////////////////////////////////////////////////////////
Explosion::Explosion() : ControllableElement(new ExplosionController)
{
	m_sprite.setTexture(*(TextureManager::Get("Explosion")));
	m_sprite.setScale(40.f / 48.f, 40.f / 48.f);

}
/////////////////////////////////////////////////////////////// niszczenie
void Explosion::SetLocation(const LocalizationVector::Vector2e& location)
{
	ControllableElement::SetLocation(location);
	m_sprite.setPosition(location.x, location.y);
	auto elementsInExploRange = Game::Instance().GetAllElements()->GetElementsLocalization(location);
	for (auto* element : elementsInExploRange)
	{
		if (dynamic_cast<Player*>(element))
		{
			int temp = element->GetLifeNumber();
			
			temp = temp -1;
			if (temp == 0) {
				element->Destroy();
			}
			element->SetLifeNumber(temp);

		}
		else
		{
			auto* tile = dynamic_cast<MapTile*>(element);
			if (tile && tile->GetType() == TileType::Dectructable)
			{
				element->Destroy();
			}
		}
	}
}
///////////////////////////////////////////////////////////////
void Explosion::Draw()
{
	Game::Instance().GetWindow().draw(m_sprite);
}
///////////////////////////////////////////////////////////////
ExplosionController::ExplosionController() : m_time_of_explosion(0.2f)
{
}
///////////////////////////////////////////////////////////////
void ExplosionController::Update(const float& deltaTime)
{
	m_time_of_explosion -= deltaTime;
	if (m_time_of_explosion <= 0)
	{
		m_owner->Destroy();
	}
}