#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<char> st;
    while (n--) {
        char c;
        cin >> c;
        if (c == '(')
            st.push('(');
        else {
            if (st.empty()) {
                cout << "No" << endl;
                return 0;
            }
            st.pop();
        }
    }

    cout << (st.empty() ? "Yes" : "No") << endl;
    return 0;
}
