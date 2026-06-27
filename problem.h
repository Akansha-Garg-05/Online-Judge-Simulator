#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
using namespace std;

class problem {
    int problem_id;
    string title;
    string difficulty;
    int points;
public:
    problem(int id, string n, string d, int p) {
        problem_id = id;
        title = n;
        difficulty = d;
        points = p;
    }
    int getId() const{
        return problem_id;
    }

    string getTitle() const{
        return title;
    }

    int getPoints() const{
        return points;
    }

    string getDifficulty() const{
        return difficulty;
    }

    void display() const {
        cout << problem_id << '\t'<<'\t' << title << '\t'<< '\t' << difficulty << '\t' <<'\t' << points << endl;
    }
};
#endif