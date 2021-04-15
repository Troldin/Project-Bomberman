#pragma once
#include "Elements.h"
class Game;

/* AllEllements - klasa zarz�dzaj�ca wszytskimi elementami*/
class AllElements final
{
public:
	typedef std::vector<Element*> ElementsVec;
	/*	Konstruktor. */
	AllElements();
	/*	Destruktor. */
	~AllElements();

	/*	Dodaje element do obecnie wy�wietlanego okna. */
	bool Add(Element* element);

	/*	Usuwa element z obecnie wy�wietlanego okna. */
	bool Remove(Element* element);

	/*	Sprawdzenie czy ju� istnieje dany element. */
	bool Exists(Element* element) const;

	/* Pobranie wekotra element�w kt�re znajduj� sie w danym "kafelku". */
	std::vector<Element*>GetElementsLocalization(const LocalizationVector::Vector2e& localization);

	/* Pobranie wekotra element�w kt�re koliduj� z podan� lokalizacj�*/
	std::vector<Element*>GetColidingTiles();

	/*	Usuni�cie ca�ego poziomu bez usuwania obiektu. */
	std::size_t Cleanup();

	/*	Uaktualnia wszystkie elementy. */
	void Update(const float& deltaTime);

	/*	Wy�wietla wszystkie elementy. */
	void Draw();

	/* Zwraca aktualn� ilo�� element�w. */
	inline std::size_t Count() const { return m_elements.size(); }

private:
	ElementsVec		m_elements;		// Wektor wszytskich element�w
};

