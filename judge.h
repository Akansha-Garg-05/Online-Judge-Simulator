#ifndef JUDGE_H
#define JUDGE_H

#include <iostream>
#include "event.h"
using namespace std;

class judge {
    priority_queue<event> events;
public:
    void addEvent(event e)
    {
        events.push(e);
    }

    bool empty()
    {
        return events.empty();
    }

    event nextEvent()
    {
        event e = events.top();
        events.pop();
        return e;
    }
    void showPendingEvents()
    {
        priority_queue<event> temp = events;

        cout << "Pending Events\n";

        while (!temp.empty())
        {
            (temp.top()).display();
            temp.pop();
        }
    }

    int totalPending()
    {
        return events.size();
    }
    void clear()
    {
        while (!events.empty())
            events.pop();
    }
};

#endif
