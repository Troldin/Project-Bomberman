#pragma once
#pragma once
#include "ControllableElements.h"
/* Typ wyliczeniowy zawieraj�cy rodzaje element�w mapy. */
enum TileType
{
	Background = 0,		// Pod�oga.
	Solid = 1,			// Niezniszczalna �ciana.
	Dectructable = 2,	// Zniszczalna �ciana.
	White = 3			// Miejsce na wynik.
};
/* MapTile - klasa element�w mapy. */
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
	/* Wy�wietlanie elementu mapy. */
	virtual void Draw() override;
	/* Pobranie typu elementu mapy. */
	inline TileType GetType() const { return tile_type; }


};
/* TileController - klasa kontrolera element�w mapy. */
class TileController : public ControllableElementController
{
public:
	/* Konstruktor. */
	explicit TileController();
	/* Uaktualnienie element�w mapy.*/
	virtual void Update(const float& deltaTime) override;
};



