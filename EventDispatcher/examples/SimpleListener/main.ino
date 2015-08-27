#include "<EventDispatcher.h>"
#include "SimpleListener.h"

void setup()
{
	SimpleListener listener;
	SimpleListener listener2;
	SimpleListener listener3;
	EventDispatcher::getInstance().addListener("event",&listener);
	EventDispatcher::getInstance().addListener("event2",&listener2);
	EventDispatcher::getInstance().addListener("event3",&listener3);

	char event[] = "event throwed\n";
	char event2[] = "event2 throwed\n";
	char event3[] = "event3 throwed\n";
	
	EventDispatcher::getInstance().throwEvent("event2",event2);
	EventDispatcher::getInstance().throwEvent("event",event);
	EventDispatcher::getInstance().throwEvent("event3",event3);

	EventDispatcher::getInstance().removeListener(&listener3);

	EventDispatcher::getInstance().throwEvent("event2",event2);
	EventDispatcher::getInstance().throwEvent("event",event);
	EventDispatcher::getInstance().throwEvent("event3",event3);
}
