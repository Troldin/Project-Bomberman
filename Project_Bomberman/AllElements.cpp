#include "AllElements.h"
#include "Game.h"
#include "Elements.h"
#include "MapTile.h"
////////////////////////////////////////////////////////////////////////////////////
AllElements::AllElements()
{
}
////////////////////////////////////////////////////////////////////////////////////
AllElements::~AllElements()
{
	this->Cleanup();
}
////////////////////////////////////////////////////////////////////////////////////
bool AllElements::Add(Element* element)
{
		if (!this->Exists(element))
		{
			m_elements.push_back(element);
			return true;
		}
}
////////////////////////////////////////////////////////////////////////////////////
bool AllElements::Remove(Element* element)
{
		auto repeatedElements = std::find(m_elements.begin(), m_elements.end(), element);
		if (repeatedElements != m_elements.end())
		{
			m_elements.erase(repeatedElements);
			return true;
		}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////
bool AllElements::Exists(Element* element) const
{
	return std::find(m_elements.begin(), m_elements.end(), element) != m_elements.end();
}
////////////////////////////////////////////////////////////////////////////////////
std::vector<Element*> AllElements::GetElementsLocalization(const LocalizationVector::Vector2e& localization)
{
	std::vector<Element*> elementsInLocalization;    // Zmienna zawieraj�ca elementy obecne w podanej lokalizacji.
	for (auto* element : m_elements)
	{
		auto tempx = element->GetLocation().x;
		auto tempy = element->GetLocation().y;
		/*If sprawdzaj�cy ca�a powierzchnie "kafalka" a nie tylko lokacje spritu. */
		if (tempx < localization.x +40  && tempy< localization.y + 40 && tempx >= localization.x&& tempy >= localization.y)
		{
			elementsInLocalization.push_back(element);
		}
	}
	return elementsInLocalization;
}
////////////////////////////////////////////////////////////////////////////////////
std::vector<Element*> AllElements::GetColidingTiles()
{
	std::vector<Element*> collidingElements; // Zmienna zawieraj�ca elementy z kt�rymi mo�e wyst�pi� kolizja
	for (auto* element : m_elements)
	{
		auto* tile = dynamic_cast<MapTile*>(element);
		if (tile && tile->GetType() != TileType::Background)
		{
			collidingElements.push_back(element);
		}
	}
	return collidingElements;
}
////////////////////////////////////////////////////////////////////////////////////
std::size_t AllElements::Cleanup()
{
	/* Usu� wszystkich aktor�w (z pami�ci, nie tylko z kontenera)*/
	std::size_t elementsCount = m_elements.size();
	for (auto* element : m_elements)
		delete element;
	return elementsCount;
}
////////////////////////////////////////////////////////////////////////////////////
void AllElements::Update(const float& deltaTime)
{
	/* Wszyscy aktorzy zostaj� uaktualnieni. */
	for (auto i =0u; i < m_elements.size();i++)
	{
		m_elements[i]->Update(deltaTime);
		if (m_elements[i]->IsDestroyed())
		{
			delete m_elements[i];
			m_elements.erase(m_elements.begin() + i);
			i--;           // erase usuwa wartosc i przesuwa wszytsko jeden do ty�u. czyli na usunietej pozycji znajduje sie element i+1
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
void AllElements::Draw()
{
	/* Wy�wietlamy ka�dego aktora. */
	for (auto* element : m_elements)
	{
		element->Draw();
	}
}