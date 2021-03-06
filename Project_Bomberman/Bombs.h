
#pragma once
#include "ControllableElements.h"

/*Klasa opisująca bomby*/
class Bombs : public ControllableElement
{
private:

	sf::Sprite		m_sprite;					//Sprite bomby

public:
	/*Konstruktor klasy Bombs*/
	Bombs();
	/*Metoda usatwijąca pozycję bomby*/
	virtual void SetLocation(const LocalizationVector::Vector2e& location) override;
	/*Metoda wyświetlająca bombę*/
	virtual void Draw() override;
};
/*Klasa kontrolera bomby*/
class BombsController : public ControllableElementController
{
private:

	float			m_time_to_explosion;		//Czas do ekspolzji bomby

public:
	/*Konstruktor klasy BombsController*/
	BombsController();
	/*Metoda uaktualniająca stan bomby*/
	virtual void Update(const float& deltaTime) override;
};
