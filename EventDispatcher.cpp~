#include "EventDispatcher.h"
#include <string.h>

EventDispatcher::EventDispatcher()
{
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
	{
		events[i] = NULL;
		listeners[i] = NULL;
	}
}

EventDispatcher::~EventDispatcher(){}

bool EventDispatcher::addListener(char event[], Listener* listener)
{
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
		if(events[i] == NULL)
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
			events[i] = NULL;
			listeners[i] = NULL;
		}
}

bool EventDispatcher::throwEvent(char event[],void* params)
{
	
	for(int i=0;i<LISTENER_LIST_SIZE;i++)
	{
		if(events[i] != NULL)
			if(strcmp (events[i],event) == 0)
					listeners[i]->onEvent(event,params);
	}
}
