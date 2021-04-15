#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "MapTile.h"
#include <fstream>
#include <iostream>
//#include <vld.h>

Game::Game()											// Konstruktor klasy z list¹ inicajlizacyjn¹.
	:								
	m_status		(GameStatus::Initializing),													
	m_window		(sf::VideoMode(800, 600, 32), "Project B0mb3rm4n", sf::Style::Close),
	m_all_elements	(new AllElements())
{
	
	
	try
	{
		TextureManager::Load("Bomberman_Front", "Data/Bomberman/Front/Bman_F_f00.png");
	}
	catch (const int code)
	{
		if (code == 20) { system("pause"); }
	}
	TextureManager::Load("Bomberman_Side",		"Data/Bomberman/Side/Bman_F_f00.png");
	TextureManager::Load("Bomberman_Back",		"Data/Bomberman/Back/Bman_B_f00.png");
	TextureManager::Load("Solid_Block",			"Data/Solid_Block.png");
	TextureManager::Load("Background",			"Data/Background.png");
	TextureManager::Load("Explodable_Block",	"Data/Explodable_Block.png");
	TextureManager::Load("White",				"Data/White.png");
	TextureManager::Load("Bomb",				"Data/Bomb.png");
	TextureManager::Load("Explosion",			"Data/Explosion.png");

	
}
///////////////////////////////////////////////////////////////
Game::~Game()		//	
{
	if (m_window.isOpen())
	{
		m_window.close();
	}

	if (m_all_elements)
		delete m_all_elements;
}
///////////////////////////////////////////////////////////////
int Game::Run()						
{
	m_status = GameStatus::Running;

	sf::Color bgColor(255, 255, 255);

	/* By prawid³owo uaktualniaæ scenê potrzebujemy czasu klatki. */
	sf::Clock GameClock;
	float DeltaTime = 1 / 60.f;		// Czas pojedyñczej klatki (60fps).

	/*Wczytywanie mapy z pliku*/
	
	
	std::fstream file("Data/Level.txt", std::ios::in);

		
	if (!file.is_open()) {return false;}
	
		std::string data;
		file >> data;
		if (data != "ProjectB0mb3rm4n") return false;
		float version;
		file >> version;
		if (version != 1.0) return false;
		int width, height;
		file >> width;
		file >> height;

		/*Generowanie mapy na podstawie danych z pliku*/
		int temp;
		for (auto y = 0u; y < height; y++) {
			for (auto x = 0u; x < width; x++) {
				file >> temp;
				if (temp != 1)
				{
					auto* new_tile_background = new MapTile(static_cast<TileType>(0));
					new_tile_background->SetLocation(LocalizationVector::Vector2e(x * 40, y * 40));
					m_all_elements->Add(new_tile_background);
				}
				if (temp != 0) {
					auto* new_tile = new MapTile(static_cast<TileType>(temp));
					new_tile->SetLocation(LocalizationVector::Vector2e(x * 40, y * 40));
					m_all_elements->Add(new_tile);
				}
			}
		}
	


	
	

	

	
	file.close();

		/*Dodawanie graczy*/
	auto* playerOne = new Player(1);
	playerOne->SetLocation(LocalizationVector::Vector2e(60, 60));
	playerOne->SetLifeNumber(3);
	m_all_elements->Add(playerOne);

	auto* playerTwo = new Player(2);
	playerTwo->SetLocation(LocalizationVector::Vector2e(740, 540));
	playerTwo->SetLifeNumber(3);
	m_all_elements->Add(playerTwo);

	

	/*	G³owna pêtla gry */
	while (m_status != GameStatus::CleaningUp)
	{
		/*	Aby zmierzyæ czas klatki potrzebujemy pobraæ czas przy jej rozpoczêciu i przy koñcu */
		float frameStartTime = GameClock.getElapsedTime().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			SetStatus(GameStatus::CleaningUp);
		}
		sf::Event windowEvent;
		while (m_window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				SetStatus(GameStatus::CleaningUp);
		}

		m_window.clear(bgColor);
		/* Uaktualnie wszytskich elementów. */
		m_all_elements->Update(DeltaTime);
		/* Wyœwietlenie wszytskich elementów. */
		m_all_elements->Draw();
		/* Wyœwietlenie wszytskich elementów na ekranie za pomoca SMFL'a. */
		m_window.display();

		DeltaTime = GameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}