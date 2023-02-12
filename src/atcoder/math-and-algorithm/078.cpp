#include <bits/stdc++.h>
using namespace std;

const int MAX_AGE = 120;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        r[a - 1].push_back(b - 1);
        r[b - 1].push_back(a - 1);
    }

    vector<int> age(n, MAX_AGE);
    queue<int> q;
    age[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : r[x]) {
            if (age[y] == MAX_AGE) {
                q.push(y);
                age[y] = min(age[y], age[x] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) cout << age[i] << endl;
    return 0;
}
