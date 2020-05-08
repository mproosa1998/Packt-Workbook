#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	// Where is the player
	Vector2f m_Position;

	// Player sprite
	Sprite m_Sprite;

	// Add a Texture
	Texture m_Texture;

	// Screen resolution
	Vector2f m_Resolution;

	// Current size of arena
	IntRect m_Arena;

	// Size of arena tile
	int m_TileSize;

	// Which direction is player facing
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	// Player health
	int m_Health;

	// Player max health
	int m_MaxHealth;

	// When was player last hit
	Time m_LastHit;

	// Speed in pixels per second
	float m_Speed;

public:

	Player();

	void spawn(IntRect area, Vector2f resolution, int tileSize);

	// Call after every game
	void resetPlayerStats();

	// Handle player getting hit by zombie
	bool hit(Time timehit);

	// How long ago was the player last hit
	Time getLastHitTime();

	// Get player location
	FloatRect getPosition();

	// WHere is player center
	Vector2f getCenter();

	// What angle is player facing
	float getRotation();

	// Send copy of sprite to main function
	Sprite getSprite();

	// Moving Player
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	// Stop Player
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	// Update once every frame
	void update(float elapsedTime, Vector2i mousePosition);

	// Speed boost
	void upgradeSpeed();

	// Health boost
	void upgradeHealth();

	// Increase maximum health
	void increaseHealthLevel(int amount);

	// Get current player health
	int getHealth();

};