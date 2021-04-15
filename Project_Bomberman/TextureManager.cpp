#include "TextureManager.h"
///////////////////////////////////////////////////////////////
TextureManager::TextureManager()
{
}
///////////////////////////////////////////////////////////////
TextureManager::~TextureManager()
{
	for (auto textureData : m_textures)
	{
		delete (textureData.second);
	}
}

///////////////////////////////////////////////////////////////
std::size_t TextureManager::Cleanup()
{
	auto& instance = Instance();

	std::size_t textureCount = instance.m_textures.size();

	for (auto textureData : instance.m_textures)
	{
		delete (textureData.second);
	}

	return textureCount;
}
///////////////////////////////////////////////////////////////
sf::Texture* TextureManager::Get(const std::string& textureName)
{
	auto& instance = Instance();

	auto textureIt = instance.m_textures.find(textureName);

	if (textureIt == instance.m_textures.end())
	{
		return nullptr;
	}
	return textureIt->second;
}
///////////////////////////////////////////////////////////////
bool TextureManager::Exists(const std::string& textureName)
{
	return TextureManager::Get(textureName) != nullptr;
}
///////////////////////////////////////////////////////////////
sf::Texture* TextureManager::Load(const std::string& textureName, const std::string& texturePath)
{
	sf::Texture* result = TextureManager::Get(textureName);

	if (result)
	{
		result->loadFromFile(texturePath);
	}
	else
	{
		result = new sf::Texture();
		result->loadFromFile(texturePath);
		Instance().m_textures[textureName] = result;
	}
	//auto temp = Exists(textureName);
	
	return result;
}
