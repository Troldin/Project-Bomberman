#pragma once
#pragma once

#include "Elements.h"

class ControllableElementController;

/*	Klasa elementów które mog¹ byæ kontrolowane w dowolny sposób (poruszanie, wybuch itp.). Dziedziczy po klasie Element. */
class ControllableElement: public Element
{
protected:
	ControllableElementController*		m_controller;		// Kontroler elemetu.
public:
	/* Konstruktor ControllableElement. */
	explicit ControllableElement(ControllableElementController* controller);
	/* Dekonstruktor ControllableElement. */
	virtual ~ControllableElement() override;
	/* Metoda uaktualniaj¹ca kontroler. */
	virtual void Update(const float& deltaTime) override;

};

	/*	Kontroler klasy ControllableElement. */
class ControllableElementController
{
private:
	/* Przypisuje w³aœcicela danego kontrolera. */
	bool Possess(ControllableElement* owner);
protected:
	ControllableElement*				m_owner;			// W³aœciciel kontrolera.
public:
	/* Konstruktor klasy kontrolera. */
	ControllableElementController();
	/* Destruktor klasy kontrolera. */
	virtual ~ControllableElementController();
	/* Funkcja uaktualniaj¹ca zmiany w ControllableElement. */
	virtual void Update(const float& deltaTime) = 0;
	/* Funkcja sprawdzaj¹ca w³aœciciela elementu. */
	inline bool IsPossessed() const { return m_owner != nullptr; }
	/*	Ustawienie dostêpu klasy ControllableElement do czlonków protected i private klasy ControllableElementController*/
	friend class ControllableElement;
};

