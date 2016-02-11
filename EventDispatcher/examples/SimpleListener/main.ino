#include "<EventDispatcher.h>"
#include "SimpleListener.h"

#define EVENT 1
#define EVENT_2 2
#define ANOTHER_EVENT 3

void setup()
{
	SimpleListener listener;
	SimpleListener listener2;
	SimpleListener listener3;
	EventDispatcher::getInstance().addListener(EVENT,&listener);
	EventDispatcher::getInstance().addListener(EVENT_2,&listener2);
	EventDispatcher::getInstance().addListener(ANOTHER_EVENT,&listener3);

	char event[] = "EVENT throwed\n";
	char event2[] = "EVENT2 throwed\n";
	char event3[] = "ANOTHER_EVENT throwed\n";
	
	EventDispatcher::getInstance().throwEvent(EVENT,event2);
	EventDispatcher::getInstance().throwEvent(EVENT_2,event);
	EventDispatcher::getInstance().throwEvent(ANOTHER_EVENT,event3);

	EventDispatcher::getInstance().removeListener(&listener3);

	EventDispatcher::getInstance().throwEvent(EVENT_2,event2);
	EventDispatcher::getInstance().throwEvent(EVENT,event);
	EventDispatcher::getInstance().throwEvent(ANOTHER_EVENT,event3);
}
