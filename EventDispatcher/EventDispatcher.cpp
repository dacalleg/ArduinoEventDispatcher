#include "EventDispatcher.h"

EventDispatcher::EventDispatcher()
{
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
	{
		events[i] = 0;
		listeners[i] = 0;
	}
}

EventDispatcher::~EventDispatcher(){}

bool EventDispatcher::addListener(char event, Listener* listener)
{
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
		if(events[i] == 0)
		{
			events[i] = event;
			listeners[i] = listener;
			break;
		}
}

bool EventDispatcher::removeListener(Listener* listener)
{
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
		if(listeners[i] == listener)
 		{
			events[i] = 0;
			listeners[i] = 0;
		}
}

bool EventDispatcher::throwEvent(char event,void* params)
{
	
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
	{
		if(events[i] != 0)
			if(events[i] == event)
					listeners[i]->onEvent(event,params);
	}
}
