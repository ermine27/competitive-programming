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

int main() {
    int d[6];
    for (int i = 0; i < 6; ++i) cin >> d[i];
    Dice dice(d);

    int q, top, front;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> top >> front;
        if (top != dice.f[0] && top != dice.f[1] && top != dice.f[5] && top != dice.f[4]) dice.right();
        while (top != dice.f[0]) dice.north();
        while (front != dice.f[1]) dice.right();
        cout << dice.f[2] << endl;
    }

    return 0;
}
