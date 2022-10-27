#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int n;
    cin >> n;
    set<string> s1, s2;

    rep(i, n){
        string si;
        cin >> si;
        if(si[0] == '!'){
            si = si.substr(1);
            if(s2.count(si)){
                cout << si;
                return 0;
            }
            s1.insert(si);
        } else {
            if(s1.count(si)){
             cout << si;
                return 0;
            }
            s2.insert(si);
        }
    }

    cout << "satisfiable";
}
