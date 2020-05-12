#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {
protected:
	Sprite m_Sprite;

	// How long does jump last
	float m_JumpDuration;

	// Is character currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;

	// Which direction is character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	// How long has jump lasted
	float m_TimeThisJump;

	// Has the player just initiated jump
	bool m_JustJumped = false;

private:
	// What is the gravity;
	float m_Gravity;

	// How fast is the character
	float m_Speed = 400;

	// Where is the player
	Vector2f m_Position;

	// Where are the characters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	// Add a texture
	Texture m_Texture;

public:
	void spawn(Vector2f startPosition, float gravity);

	// This is a pure virtual function
	bool virtual handleInput() = 0;
	// This class is now abstract and can not be instantiated

	// Where is the player
	FloatRect getPosition();

	// A Rectangle Representing the position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	// Send a copy of sprite to main
	Sprite getSprite();

	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	// Where is the center of the character
	Vector2f getCenter();

	// Call update once every fram

	void update(float elapsedTime);
};