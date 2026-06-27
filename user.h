#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class user {
    string username;
    int score;
    int solve_count;
    int rating;
    int penalty;
public:
    user(string n) {
        username = n;
        score = 0;
        solve_count = 0;
        rating = 1200;
        penalty = 0;
    }
    user(string n, int score, int rating, int solved, int penalty) {
        username = n;
        this->score = score;
        this->rating = rating;
        solve_count = solved;
        this->penalty = penalty;
    }
    string get_name() const {
        return username;
    }
    void add_penalty(int p) {
        penalty += p;
    }
    int get_penalty() const {
        return penalty;
    }
    int get_solve() const {
        return solve_count;
    }
    int get_score() const {
        return score;
    }
    int get_rating() const {
        return rating;
    }
    void add_score(int x) {
        score += x;
    }
    void inc_solve() {
        solve_count++;
    }
    void update_rating(int d) {
        rating += d;
    }
    void display() const {
        cout << username << '\t' << score << '\t' << rating << endl;
    }
    void increaseRating(int x)
    {
        rating += x;
    }

    void decreaseRating(int x)
    {
        rating -= x;

        if (rating < 0)
            rating = 0;
    }
};

#endif