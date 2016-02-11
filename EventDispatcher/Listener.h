#ifndef LISTENER_H
#define LISTENER_H

class Listener
{
	public:
    	Listener(){}
    	virtual ~Listener(){}
	virtual void onEvent(char event,void* params) = 0;
};

#endif
