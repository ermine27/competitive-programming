#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    string s;
    cin >> s;

    int sum = 45;
    int d;
    rep(i,9){
        d = s[i] - '0';
        sum -= d;
    }

    cout << sum;
    return 0;
}
