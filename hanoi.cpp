#include <iostream>
#include <vector>
using namespace std;

vector<int> A, B, C;

void show() {
    cout << "\nA: ";
    for (int i : A)
        cout << i << " ";

    cout << "\nB: ";
    for (int i : B)
        cout << i << " ";

    cout << "\nC: ";
    for (int i : C)
        cout << i << " ";

    cout << "\n";
}

void move(vector<int> &from, vector<int> &to, char x, char y) {
    int disk = from.back();
    from.pop_back();
    to.push_back(disk);

    cout << "\nMove Disk " << disk << " from " << x << " to " << y << endl;
    show();
}

void hanoi(int n, vector<int> &from, vector<int> &temp, vector<int> &to,
           char x, char y, char z) {
    if (n == 1) {
        move(from, to, x, z);
        return;
    }

    hanoi(n - 1, from, to, temp, x, z, y);
    move(from, to, x, z);
    hanoi(n - 1, temp, from, to, y, x, z);
}

int main() {
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    for (int i = n; i >= 1; i--)
        A.push_back(i);

    cout << "\nInitial State:";
    show();

    hanoi(n, A, B, C, 'A', 'B', 'C');

    return 0;
}