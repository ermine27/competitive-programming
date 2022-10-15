/*
尺取り法

参考：しゃくとり法のDequeを使ったバグりにくい実装
https://qiita.com/keroru/items/6e0a22e8c9bf2a24dc68

dequeの代わりにqueueでもいい

*/

// dequeを使って解く

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

    deque<int> deq;

    int ans = 0, score = 0;
    int rem = k;

    int i = 0;
    for(char c : s){
        ++score;
        if(c == '.'){
            deq.push_back(1);
            rem -= 1;
        } else {
            deq.push_back(0);            
        }

        while(rem < 0){
            rem += deq.front();
            deq.pop_front();
            score -= 1;
        }
        chmax(ans,score);
        ++i;
    }

    cout << ans;
    return 0;
}
