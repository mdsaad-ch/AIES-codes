#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct parameters {
    int j1, j2;
    vector<string> path;
};

int main() {
    int cap1, cap2;
    int targetJug, goal;

    cout << "Enter capacity of Jug 1 and Jug 2: ";
    cin >> cap1 >> cap2;

    cout << "Enter target jug (1 or 2): ";
    cin >> targetJug;

    cout << "Enter goal amount for target jug: ";
    cin >> goal;

    if ((targetJug == 1 && goal > cap1) ||
        (targetJug == 2 && goal > cap2)) {
        cout << "Goal exceeds target jug capacity.\n";
        return 0;
    }

    queue<parameters> q;
    set<pair<int, int>> visited;

    q.push({0, 0, {"(0,0)"}});
    visited.insert({0, 0});

    while (!q.empty()) {

        parameters curr = q.front();
        q.pop();

        if ((targetJug == 1 && curr.j1 == goal) ||
            (targetJug == 2 && curr.j2 == goal)) {

            cout << "\nSolution Found\n\n";

            for (string &step : curr.path)
                cout << step << endl;

            cout << "\nFinal State: ("
                 << curr.j1 << ", "
                 << curr.j2 << ")\n";

            return 0;
        }

        vector<pair<pair<int, int>, string>> next;

        next.push_back({{cap1, curr.j2}, "Fill Jug 1"});
        next.push_back({{curr.j1, cap2}, "Fill Jug 2"});
        next.push_back({{0, curr.j2}, "Empty Jug 1"});
        next.push_back({{curr.j1, 0}, "Empty Jug 2"});

        int transfer = min(curr.j1, cap2 - curr.j2);

        next.push_back({
            {curr.j1 - transfer,
             curr.j2 + transfer},
            "Pour Jug 1 -> Jug 2"
        });

        transfer = min(curr.j2, cap1 - curr.j1);

        next.push_back({
            {curr.j1 + transfer,
             curr.j2 - transfer},
            "Pour Jug 2 -> Jug 1"
        });

        for (auto nxt : next) {

            int nj1 = nxt.first.first;
            int nj2 = nxt.first.second;

            if (!visited.count({nj1, nj2})) {
                visited.insert({nj1, nj2});

                parameters temp;

                temp.j1 = nj1;
                temp.j2 = nj2;
                temp.path = curr.path;

                temp.path.push_back(
                    nxt.second + " -> (" +
                    to_string(nj1) + ", " +
                    to_string(nj2) + ")"
                );

                q.push(temp);
            }
        }
    }

    cout << "\nNo solution exists for the given inputs.\n";

    return 0;
}