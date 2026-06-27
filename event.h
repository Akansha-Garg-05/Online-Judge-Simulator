#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class event {
private:
    string username;
    int problemId;
    int submitTime;
    string verdict;

public:

    event(string username, int problemId, int submitTime, string verdict)
    {
        this->username = username;
        this->problemId = problemId;
        this->submitTime = submitTime;
        this->verdict = verdict;
    }

    string getUser()
    {
        return username;
    }

    int getProblemId()
    {
        return problemId;
    }

    int getSubmitTime()
    {
        return submitTime;
    }

    string getVerdict()
    {
        return verdict;
    }

    void display() const
    {
        cout << username << " submitted Problem " << problemId << " at " << submitTime << " minutes" << endl;
    }
    bool operator <(const event& e) const
    {
        return submitTime > e.submitTime;
    }
};

#endif