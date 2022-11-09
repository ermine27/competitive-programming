#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> deq;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int d, x;
            cin >> d >> x;
            if (d == 0)
                deq.push_front(x);
            else
                deq.push_back(x);
        }
        if (cmd == 1) {
            int p;
            cin >> p;
            cout << deq[p] << endl;
        }
        if (cmd == 2) {
            int d;
            cin >> d;
            if (d == 0)
                deq.pop_front();
            else
                deq.pop_back();
        }
    }

    return 0;
}
