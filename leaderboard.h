#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include "user.h"
#include <set>
using namespace std;
class cmp {
public:
    bool operator()(const pair<pair<int, int>, string>& a,
        const pair<pair<int, int>, string>& b) const {

        if (a.first.first != b.first.first)
            return a.first.first > b.first.first;

        if (a.first.second != b.first.second)
            return a.first.second < b.first.second;

        return a.second < b.second;
    }
};
class leaderboard {
    set<pair<pair<int, int>, string>, cmp> board;
public:
    void buildLeaderboard(vector<user>& users) {
        board.clear();

        for (auto& u : users) {
            board.insert({ {u.get_score(),u.get_penalty()},u.get_name() });
        }
    }

    void showLeaderboard() {
        cout << "RANK" << '\t' << "NAME" << '\t' << "SCORE" << '\t' << "PENALTY" << endl;
        int x = 1;
        for (auto& p : board) {
            cout << x << '\t' << p.second << '\t' << p.first.first << '\t' << p.first.second << endl;
            x++;
        }
    }

    int getRank(string username)
    {
        int rank = 1;

        for (auto& x : board)
        {
            if (x.second == username)
                return rank;

            rank++;
        }

        return -1;
    }
    void clear()
    {
        board.clear();
    }
};
#endif
