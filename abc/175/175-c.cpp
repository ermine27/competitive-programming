#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll x,k,d;
    cin >> x >> k >> d;

    ll c = min(k, abs(x) / d);
    k = (k - c) % 2;

    if(x >= 0){
        x -= c * d;
    } else {
        x += c * d;
    }

    if(k == 1){
        if(x >= 0) x -= d;
        else x += d;
    }

    cout << abs(x);
}
