====================
Arduino EventDispatcher
====================

EventDispatcher for Arduino is a simple, Object Oriented, lightweight and intuitive Event Manager for Arduino Device.
With this library you can develop quickly complex application using event-driven design.

Installation
------------

Copy the folder `EventDispatcher` into your Arduino `Libraries` folder, as
described in the `Arduino documentation <http://arduino.cc/en/Guide/Libraries>`_.

Usage
-----

At the top of your sketch you must include the **EventDispatcher** header file::

    #include <EventDispatcher.h>

And then for retrieve the instance of **EventDispacher**::

    EventDispatcher::getInstance();

Only one instance of EventDispatcher can exsists in your application.

Listen a Event
~~~~~~

If you want to listen an event you must create a Listener. A Listener is a class that implements the interface Listener provided by EventDispatcher Library.
Like This::

    /* SimpleListener.h */
    
    #ifndef SIMPLELISTENER_H
    #define SIMPLELISTENER_H
    
    #include "Listener.h"
    
    class SimpleListener : public Listener
    {
        public:
            void onEvent(char event,void* params);
    };
    
    #endif

Now suppose that this simple listener must listen the Event "SimpleEvent". You must inform the EventDispatcher::

    #include "EventDispatcher.h"    
    #include "SimpleListener.h"    
    
    #define SIMPLE_EVENT 1

    void setup()
    {
        SimpleListener listener;    
        EventDispatcher::getInstance().addListener(SIMPLE_EVENT,&listener);
        
        char param[] = "SimpleEvent throwed\n";
        
        EventDispatcher::getInstance().throwEvent(SIMPLE_EVENT,param);
    }

After a EventDispatcher::getInstance().throwEvent(SIMPLE_EVENT,param) the function onEvent(char event,void* params) in SimpleListener is called with "SimpleEvent" and "SimpleEvent throwed\n" params.

Listen more Events
~~~~~~

If you listeners must listen two or more events you can manage this situation in onEvent function like this::

    #include "EventDispatcher.h"
    #include "SimpleListener.h"
    
    #define SIMPLE_EVENT 1
    #define ANOTHER_EVENT 2

    void setup()
        
        SimpleListener listener;
        EventDispatcher::getInstance().addListener(SIMPLE_EVENT,&listener);
        EventDispatcher::getInstance().addListener(ANOTHER_EVENT,&listener);
        
        char param[] = "SimpleEvent throwed\n";
        char param2[] = "AnotherEvent throwed\n";
        
        EventDispatcher::getInstance().throwEvent(SIMPLE_EVENT,param);
        EventDispatcher::getInstance().throwEvent(ANOTHER_EVENT,param2);
    }

    /* SimpleListener.cpp */
    
    #include "SimpleListener.h"
    
    void SimpleListener::onEvent(char event,void* params)
    {
        if(event == SIMPLE_EVENT)
        {
            /*SimpleEvent is throwed*/
        }
        else if(event == ANOTHER_EVENT)
        {
            /*AnotherEvent is throwed*/
        }
    }

Advanced Details
----------------

Increase Listener List Size
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Define ``LISTENER_LIST_SIZE`` to whatever size you need *before*
including `EventDispatcher.h`, like so::

    #define LISTENER_LIST_SIZE   16

    #include <EventDispatcher.h>

The default size is 30

Additional Features
~~~~~~~~~~~~~~~~~~~

There are various class functions for managing the listeners:

    - You can remove listeners (``removeListener(Listener* listener)``),

For details on these functions you should review *EventDispatcher.h*.

Copyright
~~~~~~~~~

Copyright (c) 2016 Daniele Callegaro


