#ifndef CONTEST_H
#define CONTEST_H

#include <iostream>
#include "user.h"
#include "problem.h"
#include "submission.h"
#include "leaderboard.h"
#include "timer.h"
#include "judge.h"
#include "storage.h"
using namespace std;

class contest {
    vector<user> users;

    vector<problem> problems;

    vector<submission> submissions;
    leaderboard lb;
    timer t;
    judge j;
    storage st;

public:
    vector<user>& getUsers() {
        return users;
    }
    void addUser(string name) {
        user u(name);
        users.push_back(u);
        lb.buildLeaderboard(users);
    }

    void addProblem(int id, string title, string difficulty, int points) {
        problem p(id, title, difficulty, points);
        problems.push_back(p);
    }

    void showUsers() {
        cout << "NAME" << '\t' << "SCORE" << '\t' << "RATING" << endl;
        for (auto& u : users) {
            u.display();
        }
    }

    void showProblems() {
        cout << "Problem ID" << '\t' << "Title" << '\t' << '\t' << '\t' << "Difficulty" << '\t' << '\t' << "Points" << endl;
        for (auto& p : problems) {
            p.display();
        }
    }

    void showSubmissions() {
        cout << "USERNAME" << '\t' << "PROBLEM_ID" << '\t' << "SUBMISSION_TIME" << '\t' << '\t' << "VERDICT" << endl;
        for (auto& s : submissions) {
            s.display();
        }
    }
    int findUser(string username) {

        for (int i = 0;i < users.size();i++) {

            if (users[i].get_name() == username)
                return i;
        }

        return -1;
    }
    int findProblem(int problemId) {
        for (int i = 0;i < problems.size();i++) {

            if (problems[i].getId() == problemId)
                return i;
        }
        return -1;
    }
    void submit_solution(string username, int problemId, int submitTime, string verdict) {
        if (!t.contestRunning(submitTime))
        {
            cout << "Submission rejected! Contest is not running.\n";
            return;
        }

        event e(username,
            problemId,
            submitTime,
            verdict);

        j.addEvent(e);

        cout << "Submission added to Judge Queue.\n";
    }
    void processNextSubmission()
    {
        if (j.empty())
        {
            cout << "No pending submissions.\n";
            return;
        }

        event e = j.nextEvent();

        int user_idx = findUser(e.getUser());
        int prob_idx = findProblem(e.getProblemId());

        if (user_idx == -1 || prob_idx == -1)
        {
            cout << "Invalid user or problem.\n";
            return;
        }

        user& u = users[user_idx];
        problem& p = problems[prob_idx];

        submission s(
            e.getUser(),
            e.getProblemId(),
            e.getSubmitTime(),
            e.getVerdict()
        );

        submissions.push_back(s);

        if (e.getVerdict() == "AC")
        {
            u.add_score(p.getPoints());
            u.inc_solve();

            if (p.getDifficulty() == "Easy")
                u.increaseRating(10);

            else if (p.getDifficulty() == "Medium")
                u.increaseRating(20);

            else
                u.increaseRating(30);
        }
        else if (e.getVerdict() == "WA")
        {
            u.add_penalty(20);
            u.decreaseRating(2);
        }
        else if (e.getVerdict() == "TLE")
        {
            u.add_penalty(30);
            u.decreaseRating(3);
        }
        else if (e.getVerdict() == "RE")
        {
            u.add_penalty(40);
            u.decreaseRating(5);
        }

        lb.buildLeaderboard(users);

        cout << "Processed submission of "
            << e.getUser()
            << endl;
    }
    void processAllSubmissions() {
        while (!j.empty())
        {
            processNextSubmission();
        }
    }
    void showPendingEvents() {
        j.showPendingEvents();
    }
    void showLeaderboard() {
        lb.showLeaderboard();
    }

    int getRank(string username) {
        return lb.getRank(username);
    }
    void startContest(int duration)
    {
        t.startContest(0, duration);
    }

    void showTimer(int currentTime)
    {
        t.displayTimer(currentTime);
    }
    void loadData()
    {
        st.loadUsers(users);
        st.loadProblems(problems);
        st.loadSubmissions(submissions);

        lb.buildLeaderboard(users);
    }
    void saveData() {
        st.saveProblems(problems);
        st.saveSubmissions(submissions);
        st.saveUsers(users);
    }
    vector<problem>& getProblems()
    {
        return problems;
    }
    void loadDefaultProblems()
    {
        addProblem(1, "Binary_Search", "Easy", 100);
        addProblem(2, "Two_Sum", "Easy", 120);
        addProblem(3, "Merge_Intervals", "Medium", 180);
        addProblem(4, "Binary_Lifting", "Hard", 280);
        addProblem(5, "Segment_Tree", "Hard", 350);
    }
    void resetContest()
    {
        users.clear();
        submissions.clear();
        problems.clear();

        lb.clear();
        j.clear();

        loadDefaultProblems();

        saveData();

        cout << "Contest Reset Successfully.\n";
    }
};
#endif