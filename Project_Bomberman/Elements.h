
#pragma once
#include "Bomberman_main.h"
#include "Vector2e.h"

/* Element - podstawowa klasa kazdego wyswietlanego elementu */
class Element
{
protected:
	LocalizationVector::Vector2e		m_location;			// Pozycja elementu
	float								m_rotation;			// Rotacja elementu
	bool								m_destroyed;        // Stan elementu (true = zosta³ zniszczony, false = dalej istnieje)
	int									life_number;		// Iloœæ ¿yæ elementu		

public:
	/*	Konstruktor elementu.*/
	inline Element(): m_rotation(0), m_destroyed(false), life_number(0){}
	/*	Destruktor aktora.*/
	inline virtual ~Element() {}
	/*	Ustawia pozycje na zawarta w przekazanym wekotrze */
	inline virtual void SetLocation(const LocalizationVector::Vector2e& location) { m_location = location; }
	/*	Ustawia rotacjê na zawarta w zmiennej*/
	inline virtual void SetRotation(const float& rotation) { m_rotation = rotation; }
	/* Metoda pomocnicza przemieszczaj¹ca element o wekotr delta*/
	inline void Move(const LocalizationVector::Vector2e& delta) { this->SetLocation(m_location + delta); }
	/* Metoda pomocnicza obracaj¹ca element o delta*/
	inline void Rotate(const float& delta) { this->SetRotation(m_rotation + delta); }
	/* Metoda pomocnicza usuwaj¹ca element*/
	inline void Destroy() { m_destroyed = true; }
	/* Metoda uaktalniaj¹ca element*/
	inline virtual void Update(const float& deltaTime) {}
	/* Metoda wyœwietlaj¹ca element (metoda czysto wirtualna)*/
	virtual void Draw() = 0;
	/* Metoda pobieraj¹ca lokacje elementu */
	inline LocalizationVector::Vector2e	GetLocation() const { return m_location; }
	/* Metoda pobieraj¹ca rotacje elementu */
	inline float						GetRotation() const { return m_rotation; }
	/* Metoda pobieraj¹ca iloœæ ¿yæ elementu */
	inline int							GetLifeNumber() { return life_number; }
	/*Metoda ustawiaj¹ca iloœæ ¿yæ elementu*/
	inline virtual void SetLifeNumber(const int& newLifeNumber) { life_number = newLifeNumber; }
	/*Metoda sprawdzaj¹ca czy element zostal zniszczony*/
	inline bool IsDestroyed() const { return m_destroyed; }
};

