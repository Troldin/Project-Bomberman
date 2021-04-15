
#pragma once
#include "Bomberman_main.h"
#include "Vector2e.h"

/* Element - podstawowa klasa kazdego wyswietlanego elementu */
class Element
{
protected:
	LocalizationVector::Vector2e		m_location;			// Pozycja elementu
	float								m_rotation;			// Rotacja elementu
	bool								m_destroyed;        // Stan elementu (true = zosta� zniszczony, false = dalej istnieje)
	int									life_number;		// Ilo�� �y� elementu		

public:
	/*	Konstruktor elementu.*/
	inline Element(): m_rotation(0), m_destroyed(false), life_number(0){}
	/*	Destruktor aktora.*/
	inline virtual ~Element() {}
	/*	Ustawia pozycje na zawarta w przekazanym wekotrze */
	inline virtual void SetLocation(const LocalizationVector::Vector2e& location) { m_location = location; }
	/*	Ustawia rotacj� na zawarta w zmiennej*/
	inline virtual void SetRotation(const float& rotation) { m_rotation = rotation; }
	/* Metoda pomocnicza przemieszczaj�ca element o wekotr delta*/
	inline void Move(const LocalizationVector::Vector2e& delta) { this->SetLocation(m_location + delta); }
	/* Metoda pomocnicza obracaj�ca element o delta*/
	inline void Rotate(const float& delta) { this->SetRotation(m_rotation + delta); }
	/* Metoda pomocnicza usuwaj�ca element*/
	inline void Destroy() { m_destroyed = true; }
	/* Metoda uaktalniaj�ca element*/
	inline virtual void Update(const float& deltaTime) {}
	/* Metoda wy�wietlaj�ca element (metoda czysto wirtualna)*/
	virtual void Draw() = 0;
	/* Metoda pobieraj�ca lokacje elementu */
	inline LocalizationVector::Vector2e	GetLocation() const { return m_location; }
	/* Metoda pobieraj�ca rotacje elementu */
	inline float						GetRotation() const { return m_rotation; }
	/* Metoda pobieraj�ca ilo�� �y� elementu */
	inline int							GetLifeNumber() { return life_number; }
	/*Metoda ustawiaj�ca ilo�� �y� elementu*/
	inline virtual void SetLifeNumber(const int& newLifeNumber) { life_number = newLifeNumber; }
	/*Metoda sprawdzaj�ca czy element zostal zniszczony*/
	inline bool IsDestroyed() const { return m_destroyed; }
};

