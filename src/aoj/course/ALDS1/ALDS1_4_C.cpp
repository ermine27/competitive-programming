#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

int main(){
    int n;
    cin >> n;
    set<string> dic;
    string cmd, str;
    rep(i,n){
        cin >> cmd >> str;
        if(cmd == "insert"){
            dic.insert(str);
        } else {
            if(dic.count(str) > 0) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}
