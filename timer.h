#ifndef TIMER_H
#define TIMER_H

#include <iostream>
using namespace std;

class timer {
    int startTime;
    int endTime;
    bool started;

public:

    timer() {
        startTime = 0;
        endTime = 0;
        started = false;
    }

    void startContest(int start, int duration) {
        startTime = start;
        endTime = start + duration;
        started = true;
    }

    bool contestRunning(int currentTime) {

        if (!started)
            return false;

        return (currentTime >= startTime && currentTime <= endTime);
    }

    bool contestEnded(int currentTime) {

        if (!started)
            return false;

        return currentTime > endTime;
    }

    int getRemainingTime(int currentTime) {

        if (!started)
            return 0;

        if (currentTime >= endTime)
            return 0;

        return endTime - currentTime;
    }

    void displayTimer(int currentTime) {

        if (!started) {
            cout << "Contest has not started.\n";
            return;
        }

        if (contestEnded(currentTime)) {
            cout << "Contest Ended.\n";
            return;
        }

        cout << "Contest Running\n";
        cout << "Current Time : " << currentTime << endl;
        cout << "Remaining Time : "
             << getRemainingTime(currentTime)
             << " minutes\n";
    }

    int getStartTime() {
        return startTime;
    }

    int getEndTime() {
        return endTime;
    }

    bool isStarted() {
        return started;
    }
};

#endif