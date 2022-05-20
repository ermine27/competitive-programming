#include <bits/stdc++.h>
using namespace std;
#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))

int main(){
    int n,m,tt;
    cin >> n >> m;

    map<int,int> a,b;
    rep(i,n){
        cin >> tt;
        a[tt]++;
    }
    rep(i,m){
        cin >> tt;
        b[tt]++;
    }
    fore(x,b){
        a[x.first] -= x.second;

        if(a[x.first] < 0){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
