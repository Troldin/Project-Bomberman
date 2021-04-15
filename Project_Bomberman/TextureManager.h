#pragma once
#include "Bomberman_main.h"

#include <unordered_map>

/* Texture Manager - klasa zarz�dzaj�ca texturami. */
class TextureManager final
{
public:
	/* Alias skracaj�cy nazwe zbioru tekstur. */
	typedef std::unordered_map<std::string, sf::Texture*> TextureMap;
	/* Destruktor. */
	~TextureManager();
	/* Metoda �aduj�ca textury do  m_textures. */
	static sf::Texture* Load(const std::string& textureName, const std::string& texturePath);
	/* Metoda usuwaj�ca wszytskie tekstury. */
	static std::size_t	Cleanup();
	/* Metoda pozwalaj�ca na dostanie si� do textury po nazwie. */
	static sf::Texture* Get(const std::string& textureName);
	/* Metoda sprawdzaj�ca czy textura o danej nazwie jest juz wczytana. */
	static bool Exists(const std::string& textureName);
private:
	/* Konstruktor. */
	TextureManager();
	/* Stworzynie jedynej instancji gry. */
	inline static TextureManager& Instance()
	{
		static TextureManager instance;
		return instance;
	}


	TextureMap			m_textures;		// Zbi�r tekstur.
};

