#pragma once
#include "ControllableElements.h"
/* Typ wyliczeniowy zawieraj�cy mo�liwe kierunki gracza. */
enum PlayerDirection
{
	Left	=	0,
	Right	=	1,
	Up		=	2,
	Down	=	3 
};
/* Player - klasa postaci gracza. */
class Player : public ControllableElement
{
private:
	
	sf::Sprite			m_sprite;		// Sprite postaci gracza.
	PlayerDirection		m_direction;	// Kierunek postaci gracza.

public:
	/* Konstruktor. */
	Player(int PlayerOne);
	/* Ustawianie kierunku gracza. */
	void SetDirection(PlayerDirection direction);
	/* Sprawdzanie kolizji. */
	bool IsColliding();
	/*Ustawianie pozycji postaci gracza. */
	virtual void SetLocation(const LocalizationVector::Vector2e &location) override;
	/*Wy�wietlanie pozycji gracza. */
	virtual void Draw() override;
	/*Ustawianie liczby �y� gracza. */
	virtual void SetLifeNumber(const int &lifenumber) override;
	/*Pobieranie aktualnego kierunku postaci gracza. */
	inline PlayerDirection GetDirection() const { return m_direction; }
};
/* PlayerController - klasa kontrolera postaci gracza*/
class PlayerController : public ControllableElementController
{
private:
	/* Metody pomocnicze s�u�ace do poruszania si�. */
	bool MoveUp(const float& delta);
	bool MoveDown(const float& delta);
	bool MoveLeft(const float& delta);
	bool MoveRight(const float& delta);

	const float			m_moveSpeed;		// Szybko�� poruszania si� postaci gracz.
	
	const float			m_min_time_bomb;	// Minimalny czas pomi�dzy po�o�eniem kolejnej bomby
	float				m_bomb_time;		// Aktualny czas do uzyskania mo�liwosci po�o�enia bomby (gdy m_bomb_time <= 0 mo�na po�o�y� kolejn�).

public:
	int					m_player_number;	// Numer gracza.
	/*Konstuktor. */
	explicit PlayerController(int PlayerOne);
	/*Aktualizowanie kontrolera postaci. */
	virtual void Update(const float &deltaTime) override;
	inline int GetPlayerNumber() const { return m_player_number; }
};

