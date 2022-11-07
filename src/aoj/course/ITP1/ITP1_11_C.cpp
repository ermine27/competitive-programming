#include <bits/stdc++.h>
using namespace std;

struct Dice {
    vector<int> f;
    int temp;

    Dice(int (&x)[6]) {
        f.resize(6);
        for (int i = 0; i < 6; ++i) f[i] = x[i];
    }

    void north() {
        temp = f[0];
        f[0] = f[1];
        f[1] = f[5];
        f[5] = f[4];
        f[4] = temp;
    }

    void east() {
        temp = f[0];
        f[0] = f[3];
        f[3] = f[5];
        f[5] = f[2];
        f[2] = temp;
    }

    // 上の面を固定して右に回す
    void right() {
        temp = f[1];
        f[1] = f[2];
        f[2] = f[4];
        f[4] = f[3];
        f[3] = temp;
    }
};

bool checkIsSame(Dice d1, Dice d2) {
    for (int i = 0; i < 6; ++i) {
        if (i % 2 == 0)
            d2.north();
        else
            d2.east();

        for (int j = 0; j < 4; ++j) {
            if (d1.f == d2.f) return true;
            d2.right();
        }
    }

    return false;
}

int main() {
    int d[6];
    for (int i = 0; i < 6; ++i) cin >> d[i];
    Dice dice1(d);
    for (int i = 0; i < 6; ++i) cin >> d[i];
    Dice dice2(d);

    if (checkIsSame(dice1, dice2) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
