#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        if (cmd == 1) {
            int p;
            cin >> p;
            cout << arr[p] << endl;
        }
        if (cmd == 2) {
            arr.pop_back();
        }
    }

    return 0;
}
