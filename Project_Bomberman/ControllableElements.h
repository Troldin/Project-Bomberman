#pragma once
#pragma once

#include "Elements.h"

class ControllableElementController;

/*	Klasa element�w kt�re mog� by� kontrolowane w dowolny spos�b (poruszanie, wybuch itp.). Dziedziczy po klasie Element. */
class ControllableElement: public Element
{
protected:
	ControllableElementController*		m_controller;		// Kontroler elemetu.
public:
	/* Konstruktor ControllableElement. */
	explicit ControllableElement(ControllableElementController* controller);
	/* Dekonstruktor ControllableElement. */
	virtual ~ControllableElement() override;
	/* Metoda uaktualniaj�ca kontroler. */
	virtual void Update(const float& deltaTime) override;

};

	/*	Kontroler klasy ControllableElement. */
class ControllableElementController
{
private:
	/* Przypisuje w�a�cicela danego kontrolera. */
	bool Possess(ControllableElement* owner);
protected:
	ControllableElement*				m_owner;			// W�a�ciciel kontrolera.
public:
	/* Konstruktor klasy kontrolera. */
	ControllableElementController();
	/* Destruktor klasy kontrolera. */
	virtual ~ControllableElementController();
	/* Funkcja uaktualniaj�ca zmiany w ControllableElement. */
	virtual void Update(const float& deltaTime) = 0;
	/* Funkcja sprawdzaj�ca w�a�ciciela elementu. */
	inline bool IsPossessed() const { return m_owner != nullptr; }
	/*	Ustawienie dost�pu klasy ControllableElement do czlonk�w protected i private klasy ControllableElementController*/
	friend class ControllableElement;
};

