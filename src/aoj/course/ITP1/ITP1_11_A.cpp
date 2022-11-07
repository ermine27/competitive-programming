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

    void south() {
        temp = f[0];
        f[0] = f[4];
        f[4] = f[5];
        f[5] = f[1];
        f[1] = temp;
    }

    void east() {
        temp = f[0];
        f[0] = f[3];
        f[3] = f[5];
        f[5] = f[2];
        f[2] = temp;
    }

    void west() {
        temp = f[0];
        f[0] = f[2];
        f[2] = f[5];
        f[5] = f[3];
        f[3] = temp;
    }

    void rotate(char c) {
        if (c == 'N') this->north();
        if (c == 'S') this->south();
        if (c == 'E') this->east();
        if (c == 'W') this->west();
    }
};

int main() {
    int d[6];
    for (int i = 0; i < 6; ++i) cin >> d[i];
    string s;
    cin >> s;

    Dice dice(d);
    for (int i = 0; i < (int)s.length(); ++i) dice.rotate(s[i]);

    cout << dice.f[0] << endl;
}
