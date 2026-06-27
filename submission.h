#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <iostream>
using namespace std;

class submission {
    string username;
    int problem_id;
    int submission_time;
    string verdict;
public:
    submission(string n, int id, int time, string v) {
        username = n;
        problem_id = id;
        submission_time = time;
        verdict = v;
    }
    string getUser() const{
        return username;
    }

    int getProblemId() const{
        return problem_id;
    }

    int getTime() const{
        return submission_time;
    }

    string getVerdict() const {
        return verdict;
    }

    void display() const{
        cout << username << '\t' << '\t' << '\t' << problem_id << '\t' << '\t'  << submission_time << '\t' << '\t' << verdict << endl;
    }
};
#endif