#pragma once

# include "Bomberman_main.h"
#include "AllElements.h"

/*	Game - klasa zarz¹dzaj¹ca rozgrywk¹. */
class Game final
{
public:
	/*Typ wyliczeniowy zawieraj¹cy mo¿liwe stany gry. */
	enum GameStatus
	{
		Initializing = 0,			
		Running		 = 1,			
		Paused		 = 2,			
		CleaningUp   = 3			
	};

	/* Destruktor. */
	~Game();
	/*	Uruchamia glowny kod gry. */
	int Run();
	/* Zwraca status gry. */
	inline GameStatus GetStatus() const { return m_status; }
	/* Ustawia status gry. */
	inline GameStatus SetStatus(const GameStatus newStatus) { return m_status = newStatus; };
	/* Zwraca okno gry. */
	inline sf::RenderWindow& GetWindow() { return m_window; }
	/* Zwraca aktualny poziom gry. */
	inline AllElements *GetAllElements() { return m_all_elements; }
	/* Stowrzenie instancji gry typu static. */
	inline static Game& Instance()
	{
		static Game instance;
		return instance;
	}
private:
	/*Konstuktor. */
	Game();

	GameStatus				m_status;			// Obecny status gry
	sf::RenderWindow		m_window;			// Obecne okno gry.
	AllElements*			m_all_elements;		// Obecny zbiór wszytskich elementów.

};

