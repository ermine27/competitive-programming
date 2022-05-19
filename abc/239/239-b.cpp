#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll x,ans;
    cin >> x;

    int m = x % 10;

    ans = x/10;
    if(x < 0 && m != 0) --ans;

    cout << ans;
}
