#pragma once
#pragma once
#include "ControllableElements.h"
/* Typ wyliczeniowy zawieraj¹cy rodzaje elementów mapy. */
enum TileType
{
	Background = 0,		// Pod³oga.
	Solid = 1,			// Niezniszczalna œciana.
	Dectructable = 2,	// Zniszczalna œciana.
	White = 3			// Miejsce na wynik.
};
/* MapTile - klasa elementów mapy. */
class MapTile : public ControllableElement
{
private:

	sf::Sprite		 m_sprite;		// Sprite elementu mapy.
	TileType		 tile_type;		// Typ elementu mapy.

public:
	/* Konstruktor. */
	 MapTile(TileType tiletype);
	/* Ustawianie lokacji elemntu mapy. */
	virtual void SetLocation(const LocalizationVector::Vector2e& location) override;
	/* Wyœwietlanie elementu mapy. */
	virtual void Draw() override;
	/* Pobranie typu elementu mapy. */
	inline TileType GetType() const { return tile_type; }


};
/* TileController - klasa kontrolera elementów mapy. */
class TileController : public ControllableElementController
{
public:
	/* Konstruktor. */
	explicit TileController();
	/* Uaktualnienie elementów mapy.*/
	virtual void Update(const float& deltaTime) override;
};



