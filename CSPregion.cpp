#include <iostream>
using namespace std;

int color[10];
int graph[10][10];
int n, m;

bool safe(int i, int c) {
    for (int j = 0; j < n; j++) {
        if (graph[i][j] && color[j] == c)
            return false;
    }
    return true;
}

bool solve(int i) {
    if (i == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (safe(i, c)) {
            color[i] = c;

            if (solve(i + 1))
                return true;

            color[i] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter number of regions: ";
    cin >> n;

    cout << "Enter number of colors: ";
    cin >> m;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    if (solve(0)) {
        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++) {
            cout << "Region " << i + 1
                 << " = Color " << color[i] << endl;
        }
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}