#include "MapTile.h"

#include "Game.h"
#include "TextureManager.h"

MapTile::MapTile(TileType tiletype ) : ControllableElement(new TileController), tile_type(tiletype)
{
	/* Ustawianie odpowdniego sprita.*/
	switch (tiletype)
	{
	case Background:
		m_sprite.setTexture(*(TextureManager::Get("Background")));
		break;
	case Solid:
		m_sprite.setTexture(*(TextureManager::Get("Solid_Block")));
		break;
	case Dectructable:
		m_sprite.setTexture(*(TextureManager::Get("Explodable_Block")));
		break;
	case White:
		m_sprite.setTexture(*(TextureManager::Get("White")));
		break;
	}
}
///////////////////////////////////////////////////////////////
void MapTile::SetLocation(const LocalizationVector::Vector2e& location)
{
	ControllableElement::SetLocation(location);
	m_sprite.setPosition(location.x, location.y);
}
///////////////////////////////////////////////////////////////
void MapTile::Draw()
{
	Game::Instance().GetWindow().draw(m_sprite);
}
///////////////////////////////////////////////////////////////
TileController::TileController()
{
}
///////////////////////////////////////////////////////////////
void TileController::Update(const float& deltaTime)
{

}

