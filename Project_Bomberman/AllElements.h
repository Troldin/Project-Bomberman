#pragma once
#include "Elements.h"
class Game;

/* AllEllements - klasa zarz¹dzaj¹ca wszytskimi elementami*/
class AllElements final
{
public:
	typedef std::vector<Element*> ElementsVec;
	/*	Konstruktor. */
	AllElements();
	/*	Destruktor. */
	~AllElements();

	/*	Dodaje element do obecnie wyœwietlanego okna. */
	bool Add(Element* element);

	/*	Usuwa element z obecnie wyœwietlanego okna. */
	bool Remove(Element* element);

	/*	Sprawdzenie czy ju¿ istnieje dany element. */
	bool Exists(Element* element) const;

	/* Pobranie wekotra elementów które znajduj¹ sie w danym "kafelku". */
	std::vector<Element*>GetElementsLocalization(const LocalizationVector::Vector2e& localization);

	/* Pobranie wekotra elementów które koliduj¹ z podan¹ lokalizacj¹*/
	std::vector<Element*>GetColidingTiles();

	/*	Usuniêcie ca³ego poziomu bez usuwania obiektu. */
	std::size_t Cleanup();

	/*	Uaktualnia wszystkie elementy. */
	void Update(const float& deltaTime);

	/*	Wyœwietla wszystkie elementy. */
	void Draw();

	/* Zwraca aktualn¹ iloœæ elementów. */
	inline std::size_t Count() const { return m_elements.size(); }

private:
	ElementsVec		m_elements;		// Wektor wszytskich elementów
};

