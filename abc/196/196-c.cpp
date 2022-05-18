#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    string n;
    cin >> n;

    int ns = n.length();
    if(ns == 1){
        cout << 0;
        return 0;
    }
    if(ns % 2 == 1) {
        n = to_string(pow(10, ns - 1) - 1);
        --ns;
    }

    ns /= 2;
    int n1 = stoi(n.substr(0, ns));
    int n2 = stoi(n.substr(ns));

    int ans;
    if(n1 > n2)  ans = n1 - 1;
    else ans = n1;

    cout << ans;
}