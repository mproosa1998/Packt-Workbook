#pragma once
#include "PlayableCharacter.h"

class Bob :public PlayableCharacter {
public:
	// Constuctor Specific to Bob
	Bob();

	// Input Handler for Bob
	bool virtual handleInput();
};