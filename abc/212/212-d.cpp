#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vl = vector<long long>;


// multisetを使って解く
int main(){
    int q;
    cin >> q;

    multiset<ll> bag;
    ll adding = 0;

    rep(i,q){
        ll qi,xi;
        cin >> qi;
        if(qi != 3){
            cin >> xi;
        }

        if(qi == 1){
            bag.insert(xi - adding);
        }
        if(qi == 2){
            adding += xi;
        }
        if(qi == 3){
            ll mval = *begin(bag);
            bag.erase(bag.find(mval));
            mval += adding;
            cout << mval << endl;
        }
    }

    return 0;    
}
