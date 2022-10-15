#include <bits/stdc++.h>
using namespace std;
#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    int n,ai;
    cin >> n;
    set<int> s;
    rep(i,n){
        cin >> ai;
        s.insert(ai);
    }
    cout << s.size();
}
