#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	Bat bat(1920 / 2, 1080 - 20);

	// Creat a ball
	Ball ball(1920 / 2, 0);

	// Create a Text object called HUD
	Text hud;

	// A cool retro-style font
	Font font;
	font.loadFromFile("fonts/DS-DIGIT.ttf");

	// Set the font
	hud.setFont(font);

	// Set the size
	hud.setCharacterSize(75);

	// Set the color
	hud.setFillColor(Color::White);

	hud.setPosition(20, 20);

	// Here is our clock for timing everything
	Clock clock;

	while (window.isOpen()) {

		// Handle player input
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				// Wuit the game when the window is closed
				window.close();
		}

		// Handle player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Handle pressing and releasing of arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			bat.moveLeft();
		}
		else {
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			bat.moveRight();
		}
		else {
			bat.stopRight();
		}


		// Update Section

		// Update the delta time
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		
		// Update the HUD text
		std::stringstream ss;
		ss << "Score: " << score << "   Lives: " << lives;
		hud.setString(ss.str());

		// Handle the ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y) {
			// Reset the ball at top of screen
			ball.reboundBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if (lives < 1) {
				// Reset the score
				score = 0;
				// Reset the lives
				lives = 3;
			}
		}

		// Handle the ball hitting the top
		if (ball.getPosition().top < 0) {
			ball.reboundBatOrTop();

			// Add a point to the player's score
			score++;
		}

		// Handle the bat hitting the sides
		if (ball.getPosition().left<0 ||
			ball.getPosition().left + ball.getPosition().width>window.getSize().x) {

			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition())) {
			// Hit detected so reverse ball
			ball.reboundBatOrTop();
		}


		// Draw
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}