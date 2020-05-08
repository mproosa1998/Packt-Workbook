#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pickup {
private:
	// Start value for pickups
	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	const int START_WAIT_TIME = 10;
	const int START_SECONDS_TO_LIVE = 5;

	// Sprite that represents pickup
	Sprite m_Sprite;

	// Arena it exists in
	IntRect m_Arena;

	// How much pickup is worth
	int m_Value;

	// What type of pickup is this?
	// 1 = health, 2 = amma
	int m_Type;

	// Handle the spawning and disappearing
	bool m_Spawned;
	float m_SecondsSinceSpawned;
	float m_SecondsSinceDeSpawn;
	float m_SecondsToLive;
	float m_SecondsToWait;

public:
	Pickup(int type);

	// Prepare a new pickup
	void setArena(IntRect arena);

	void spawn();

	// Sheck position of a pickup
	FloatRect getPosition();

	// Get the sprite for drawing
	Sprite getSprite();

	// Update pickup each frame
	void update(float elapsedTime);

	// Is pickup currently spawned?
	bool isSpawned();

	// Get the contents of pickup
	int gotIt();

	// Upgrade pickup value
	void upgrade();

};