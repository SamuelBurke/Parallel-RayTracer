#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

//! Deals with the keyboard input.
class Input
{
public:
	// Called each frame, gets the current keyboard state.
	void Tick();

	// Checks if the key passed into the keyCode parameter is the same as the 'mCurrentKeys' variable.
	bool isKeyPressed(SDL_Scancode _keyCode);

private:
	const Uint8* mCurrentKeys; // Stores the current keys being pressed, updated in 'Tick'
};


#endif // !INPUT_H
