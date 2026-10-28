#include <iostream>
#include <algorithm>
using namespace std;

char b[3][3] = {{' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}};

void show() {
    for (int i = 0; i < 3; i++) {
        cout << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << endl;
        if (i < 2) cout << "--+---+--\n";
    }
}

bool win(char p) {
    for (int i = 0; i < 3; i++)
        if ((b[i][0] == p && b[i][1] == p && b[i][2] == p) ||
            (b[0][i] == p && b[1][i] == p && b[2][i] == p))
            return true;

    return (b[0][0] == p && b[1][1] == p && b[2][2] == p) ||
           (b[0][2] == p && b[1][1] == p && b[2][0] == p);
}

bool full() {
    for (auto &row : b)
        for (char c : row)
            if (c == ' ') return false;
    return true;
}

int minimax(bool ai) {
    if (win('O')) return 10;
    if (win('X')) return -10;
    if (full()) return 0;

    int best = ai ? -1000 : 1000;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == ' ') {
                b[i][j] = ai ? 'O' : 'X';
                int score = minimax(!ai);
                b[i][j] = ' ';
                best = ai ? max(best, score) : min(best, score);
            }

    return best;
}

void computer() {
    int best = -1000, r = -1, c = -1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == ' ') {
                b[i][j] = 'O';
                int score = minimax(false);
                b[i][j] = ' ';

                if (score > best)
                    best = score, r = i, c = j;
            }

    if (r != -1) b[r][c] = 'O';
}

int main() {
    int r, c;
    cout << "You are X, Computer is O\n";

    while (true) {
        show();
        cout << "Enter row and column (0-2): ";
        cin >> r >> c;

        if (r < 0 || r > 2 || c < 0 || c > 2 || b[r][c] != ' ') {
            cout << "Invalid move!\n";
            continue;
        }

        b[r][c] = 'X';

        if (win('X')) { show(); cout << "You win!\n"; break; }
        if (full()) { show(); cout << "Draw!\n"; break; }

        computer();

        if (win('O')) { show(); cout << "Computer wins!\n"; break; }
        if (full()) { show(); cout << "Draw!\n"; break; }
    }
}
