#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    int n;
    cin >> n;
    map<string,int> m;

    rep(i,n){
        string si;
        int cnt;
        cin >> si;
        m[si]++;
        cnt = m[si] - 1;

        cout << si;
        if (cnt > 0) {
            cout << '(' << cnt << ')';
        }
        cout << endl;
    }

    return 0;
}
