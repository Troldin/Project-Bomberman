
#pragma once
#include "ControllableElements.h"

/*Klasa opisuj¹ca bomby*/
class Bombs : public ControllableElement
{
private:

	sf::Sprite		m_sprite;					//Sprite bomby

public:
	/*Konstruktor klasy Bombs*/
	Bombs();
	/*Metoda usatwij¹ca pozycjê bomby*/
	virtual void SetLocation(const LocalizationVector::Vector2e& location) override;
	/*Metoda wyœwietlaj¹ca bombê*/
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
	/*Metoda uaktualniaj¹ca stan bomby*/
	virtual void Update(const float& deltaTime) override;
};
