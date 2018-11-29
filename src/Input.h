#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input
{
public:
	void Tick();
	bool isKeyPressed(SDL_Scancode _keyCode);

private:
	const Uint8* m_currentKeys;
};


#endif // !INPUT_H
