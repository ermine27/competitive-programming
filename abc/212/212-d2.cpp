#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vl = vector<long long>;


// priority_queueを使って解く（公式解説はこっち）
int main(){
    int q;
    cin >> q;

    priority_queue<ll, vl, greater<ll>> pq;
    ll adding = 0;

    rep(i,q){
        ll qi,xi;
        cin >> qi;
        if(qi != 3){
            cin >> xi;
        }

        if(qi == 1){
            pq.push(xi - adding);
        }
        if(qi == 2){
            adding += xi;
        }
        if(qi == 3){
            ll mval = pq.top();
            pq.pop();
            mval += adding;
            cout << mval << endl;
        }
    }

    return 0;    
}