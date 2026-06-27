#include <iostream>
#include "contest.h"

using namespace std;

int main()
{
    contest c;

    c.loadData();

    if (c.getProblems().empty())
    {
        c.loadDefaultProblems();
    }

    c.startContest(180);

    int choice;

    do
    {
        cout << "\n========== ONLINE JUDGE SIMULATOR ==========\n";
        cout << "1. Add User\n";
        cout << "2. Show Users\n";
        cout << "3. Show Problems\n";
        cout << "4. Submit Solution\n";
        cout << "5. Process Next Submission\n";
        cout << "6. Process All Submissions\n";
        cout << "7. Show Pending Queue\n";
        cout << "8. Show Submissions\n";
        cout << "9. Show Leaderboard\n";
        cout << "10. Show User Rank\n";
        cout << "11. Show Contest Timer\n";
        cout << "12. Save Data\n";
        cout << "13. Reset Contest\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter Username : ";
            cin >> name;

            c.addUser(name);
            break;
        }

        case 2:
        {
            c.showUsers();
            break;
        }

        case 3:
        {
            c.showProblems();
            break;
        }

        case 4:
        {
            string username;
            int pid;
            int time;
            int v;

            cout << "Username : ";
            cin >> username;

            cout << "Problem ID : ";
            cin >> pid;

            cout << "Submission Time : ";
            cin >> time;

            cout << "\nSelect Verdict\n";
            cout << "1. AC\n";
            cout << "2. WA\n";
            cout << "3. TLE\n";
            cout << "4. RE\n";
            cout << "5. CE\n";

            cin >> v;

            string verdict;

            switch (v)
            {
            case 1:
                verdict = "AC";
                break;
            case 2:
                verdict = "WA";
                break;
            case 3:
                verdict = "TLE";
                break;
            case 4:
                verdict = "RE";
                break;
            default:
                verdict = "CE";
            }

            c.submit_solution(username, pid, time, verdict);

            break;
        }

        case 5:
        {
            c.processNextSubmission();
            break;
        }

        case 6:
        {
            c.processAllSubmissions();
            break;
        }

        case 7:
        {
            c.showPendingEvents();
            break;
        }

        case 8:
        {
            c.showSubmissions();
            break;
        }

        case 9:
        {
            c.showLeaderboard();
            break;
        }

        case 10:
        {
            string name;

            cout << "Enter Username : ";
            cin >> name;

            cout << "Rank : "
                << c.getRank(name)
                << endl;

            break;
        }

        case 11:
        {
            int currentTime;

            cout << "Current Time : ";
            cin >> currentTime;

            c.showTimer(currentTime);

            break;
        }

        case 12:
        {
            c.saveData();
            cout << "Data Saved Successfully.\n";
            break;
        }
        case 13:
        {
            char ch;

            cout << "This will delete all users and submissions.\n";
            cout << "Are you sure? (Y/N): ";
            cin >> ch;

            if (ch == 'Y' || ch == 'y')
                c.resetContest();

            break;
        }
        case 0:
        {
            c.saveData();
            cout << "Thank You!\n";
            break;
        }

        default:
        {
            cout << "Invalid Choice\n";
        }
        }

    } while (choice != 0);

    return 0;
}