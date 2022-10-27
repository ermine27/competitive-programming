// queueを使って解く

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    string s;
    int k, len;
    cin >> s >> k;

    queue<int> q;

    int ans = 0, score = 0;
    int rem = k;

    for(char c : s){
        ++score;
        if(c == '.'){
            q.push(1);
            --rem;
        } else {
            q.push(0);            
        }

        while(rem < 0){
            rem += q.front();
            q.pop();
            --score;
        }
        chmax(ans,score);
    }

    cout << ans;
}
