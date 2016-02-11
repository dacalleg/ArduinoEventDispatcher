#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#ifndef LISTENER_LIST_SIZE
#define LISTENER_LIST_SIZE 30
#endif

#include "Listener.h"

class EventDispatcher
{
	public:
		static EventDispatcher& getInstance()
		{
		    static EventDispatcher instance;
		    return instance;
		}
		bool addListener(char event, Listener* listener);
		bool removeListener(Listener* listener);
		bool throwEvent(char event,void* params);
		
		~EventDispatcher();
	private:
		char events[LISTENER_LIST_SIZE];
		Listener *listeners[LISTENER_LIST_SIZE];
		EventDispatcher();
		EventDispatcher(EventDispatcher const&);
		void operator=(EventDispatcher const&);
};

#endif
