# Online Judge Simulator (C++)

A console-based **Online Judge Simulator** built in **C++** using **Object-Oriented Programming (OOP)** and the **Standard Template Library (STL)**. The project simulates the core workflow of an online coding platform by allowing users to register, solve problems, submit solutions, process submissions through a judge queue, and view an automatically updated leaderboard.

---

## Features

* 👤 User Registration
* 📚 Default Problem Set
* 📤 Solution Submission
* ⚖️ Judge Queue using Priority Queue
* ✅ Verdict Simulation (AC, WA, TLE, RE, CE)
* ⏱ Contest Timer
* 🏆 Dynamic Leaderboard
* 📈 Rating Update System
* ⚠️ Penalty Calculation
* 💾 Persistent Storage using Text Files
* 🔄 Contest Reset

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Standard Template Library (STL)
* File Handling

---

## Data Structures Used

* `vector`
* `set`
* `priority_queue`
* `pair`

---

## OOP Concepts Implemented

* Classes and Objects
* Encapsulation
* Constructors
* Header File Organization
* Composition

---

## Project Structure

```
Online-Judge-Simulator/
│
├── main.cpp
├── contest.h
├── user.h
├── problem.h
├── submission.h
├── leaderboard.h
├── judge.h
├── event.h
├── timer.h
├── storage.h
│
├── users.txt
├── problems.txt
├── submissions.txt
│
└── README.md
```

---

## Default Problems

| ID | Problem         | Difficulty | Points |
| -- | --------------- | ---------- | -----: |
| 1  | Binary Search   | Easy       |    100 |
| 2  | Two Sum         | Easy       |    120 |
| 3  | Merge Intervals | Medium     |    180 |
| 4  | Binary Lifting  | Hard       |    280 |
| 5  | Segment Tree    | Hard       |    350 |

---

## Supported Verdicts

* AC (Accepted)
* WA (Wrong Answer)
* TLE (Time Limit Exceeded)
* RE (Runtime Error)
* CE (Compilation Error)

---

## How It Works

1. Register users.
2. Load the default problems.
3. Start the contest timer.
4. Submit a solution.
5. The submission is added to the judge queue.
6. Process submissions.
7. Update score, rating and penalty.
8. Refresh the leaderboard.
9. Save data for future sessions.

---

## Leaderboard Rules

* Higher score ranks first.
* If scores are equal, lower penalty ranks higher.
* Rankings update automatically after processed submissions.

---

## Persistent Storage

Contest data is stored locally using text files:

* `users.txt`
* `problems.txt`
* `submissions.txt`

This allows the simulator to preserve data between program runs.

---

## Sample Menu

```
========== ONLINE JUDGE SIMULATOR ==========

1. Add User
2. Show Users
3. Show Problems
4. Submit Solution
5. Process Next Submission
6. Process All Submissions
7. Show Pending Queue
8. Show Submissions
9. Show Leaderboard
10. Show User Rank
11. Show Contest Timer
12. Save Data
13. Reset Contest
0. Exit
```

---

## Future Improvements

* Automatic judging using hidden test cases
* Multiple contests
* Login system
* SQL database integration
* GUI version
* Web-based version
* Runtime and memory usage simulation

---

## Author

**Akansha**

GitHub: https://github.com/Akansha-Garg-05
