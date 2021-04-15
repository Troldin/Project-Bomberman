#pragma once
#include "Bomberman_main.h"

#include <unordered_map>

/* Texture Manager - klasa zarz¹dzaj¹ca texturami. */
class TextureManager final
{
public:
	/* Alias skracaj¹cy nazwe zbioru tekstur. */
	typedef std::unordered_map<std::string, sf::Texture*> TextureMap;
	/* Destruktor. */
	~TextureManager();
	/* Metoda ³aduj¹ca textury do  m_textures. */
	static sf::Texture* Load(const std::string& textureName, const std::string& texturePath);
	/* Metoda usuwaj¹ca wszytskie tekstury. */
	static std::size_t	Cleanup();
	/* Metoda pozwalaj¹ca na dostanie siê do textury po nazwie. */
	static sf::Texture* Get(const std::string& textureName);
	/* Metoda sprawdzaj¹ca czy textura o danej nazwie jest juz wczytana. */
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


	TextureMap			m_textures;		// Zbiór tekstur.
};

