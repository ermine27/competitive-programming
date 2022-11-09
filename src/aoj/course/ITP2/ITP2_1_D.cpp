#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n);
    for (int i = 0; i < q; ++i) {
        int cmd, t;
        cin >> cmd >> t;

        if (cmd == 0) {
            int z;
            cin >> z;
            arr[t].push_back(z);
        }
        if (cmd == 1) {
            for (int j = 0; j < (int)arr[t].size(); ++j) {
                if (j != 0) cout << ' ';
                cout << arr[t][j];
            }
            cout << endl;
        }
        if (cmd == 2) {
            arr[t].clear();
        }
    }

    return 0;
}
