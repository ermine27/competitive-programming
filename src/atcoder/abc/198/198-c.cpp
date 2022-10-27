#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll r,x,y;
    cin >> r >> x >> y;

    ll u = pow(x,2) + pow(y,2);


    int ans = 1;
    while(pow(r*ans, 2) < u){
        ++ans;
    }

    if(ans == 1 && u < pow(r*ans, 2)){
        ans = 2;
    }

    cout << ans;
}