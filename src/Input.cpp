#include "Input.h"

#include <iostream>

void Input::Tick()
{
	m_currentKeys = SDL_GetKeyboardState(NULL);
}

bool Input::isKeyPressed(SDL_Scancode _keyCode)
{
	if (m_currentKeys[_keyCode]) { return true; }
	else { return false; }
}