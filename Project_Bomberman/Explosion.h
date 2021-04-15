#pragma once
#include "ControllableElements.h"

/* Explosion - klasa wybuchu. */
class Explosion : public ControllableElement
{
private:
		
	sf::Sprite		m_sprite;				// Sprite wybuchu.

public:
	/* Konstruktor. */
	Explosion();
	/* Ustawianie lokacji wybuchu. */
	virtual void SetLocation(const LocalizationVector::Vector2e& location) override;
	/* Wyœwietlanie wybuchu. */
	virtual void Draw() override;
};
/* ExplosionController - klasa kontrolera wybuchu. */
class ExplosionController : public ControllableElementController
{
private:

	float			m_time_of_explosion;	// Czas trawania wybuchu.element

public:
	/* Konstruktor. */
	ExplosionController();
	/* Uaktualnianie stanu bomby. */
	virtual void Update(const float& deltaTime) override;
};