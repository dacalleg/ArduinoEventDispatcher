#ifndef SIMPLELISTENER_H
#define SIMPLELISTENER_H

#include "<Listener.h>"

class SimpleListener : public Listener
{
	public:
		void onEvent(char event[],void* params);
};

#endif
