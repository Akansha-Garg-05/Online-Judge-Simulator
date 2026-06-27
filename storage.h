#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "user.h"
#include "problem.h"
#include "submission.h"

using namespace std;

class storage {

public:

    // ---------------- USERS ----------------

    void saveUsers(const vector<user>& users)
    {
        ofstream out("users.txt");

        if (!out)
        {
            cout << "Error opening users.txt\n";
            return;
        }

        for (const auto &u : users)
        {
            out << u.get_name() << " "
                << u.get_score() << " "
                << u.get_rating() << " "
                << u.get_solve() << " "
                << u.get_penalty() << '\n';
        }

        out.close();
    }

    void loadUsers(vector<user>& users)
    {
        ifstream in("users.txt");

        if (!in)
            return;

        users.clear();

        string name;
        int score, rating, solved, penalty;

        while (in >> name >> score >> rating >> solved >> penalty)
        {
            users.push_back(
                user(name, score, rating, solved, penalty)
            );
        }

        in.close();
    }

    // ---------------- PROBLEMS ----------------

    void saveProblems(const vector<problem>& problems)
    {
        ofstream out("problems.txt");

        if (!out)
        {
            cout << "Error opening problems.txt\n";
            return;
        }

        for (const auto &p : problems)
        {
            out << p.getId() << " "
                << p.getTitle() << " "
                << p.getDifficulty() << " "
                << p.getPoints() << '\n';
        }

        out.close();
    }

    void loadProblems(vector<problem>& problems)
    {
        ifstream in("problems.txt");

        if (!in)
            return;

        problems.clear();

        int id;
        string title, difficulty;
        int points;

        while (in >> id >> title >> difficulty >> points)
        {
            problems.push_back(
                problem(id, title, difficulty, points)
            );
        }

        in.close();
    }

    // ---------------- SUBMISSIONS ----------------

    void saveSubmissions(const vector<submission>& submissions)
    {
        ofstream out("submissions.txt");

        if (!out)
        {
            cout << "Error opening submissions.txt\n";
            return;
        }

        for (const auto &s : submissions)
        {
            out << s.getUser() << " "
                << s.getProblemId() << " "
                << s.getTime() << " "
                << s.getVerdict() << '\n';
        }

        out.close();
    }

    void loadSubmissions(vector<submission>& submissions)
    {
        ifstream in("submissions.txt");

        if (!in)
            return;

        submissions.clear();

        string username;
        int problemId, submitTime;
        string verdict;

        while (in >> username >> problemId >> submitTime >> verdict)
        {
            submissions.push_back(
                submission(username, problemId, submitTime, verdict)
            );
        }

        in.close();
    }
};

#endif