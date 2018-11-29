#ifndef APPLICATION_H
#define APPLICATION_H

#include "Program.h"

class Application
{
public:
	void Initialise();
	void Loop();
	void cleanup();

private:
	bool m_quit;

	Input m_input;
	Window m_window;

};

#endif // !APPLICATION_H
