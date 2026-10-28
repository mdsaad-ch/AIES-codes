
#include <iostream>
using namespace std;

int d[10];
bool used[10];

bool solve(int i) {
    if (i == 8) {
        int SEND = d[0]*1000 + d[1]*100 + d[2]*10 + d[3];
        int MORE = d[4]*1000 + d[5]*100 + d[6]*10 + d[1];
        int MONEY = d[4]*10000 + d[5]*1000 + d[2]*100 + d[1]*10 + d[7];

        return SEND + MORE == MONEY;
    }

    for (int x = 0; x <= 9; x++) {
        if (used[x]) continue;
        if (x == 0 && (i == 0 || i == 4)) continue;

        d[i] = x;
        used[x] = true;

        if (solve(i + 1)) return true;

        used[x] = false;
    }
    return false;
}

int main() {
    if (solve(0)) {
        cout << "Solution:\n";
        cout << "S=" << d[0] << " E=" << d[1] << " N=" << d[2]
             << " D=" << d[3] << endl;
        cout << "M=" << d[4] << " O=" << d[5] << " R=" << d[6]
             << " Y=" << d[7] << endl;

        cout << d[0] << d[1] << d[2] << d[3] << " + "
             << d[4] << d[5] << d[6] << d[1] << " = "
             << d[4] << d[5] << d[2] << d[1] << d[7];
    }
}