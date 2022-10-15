#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll a,b;
    int k,ans = 0;
    cin >> a >> b >> k;

    while(a < b){
        a *= k;
        ++ans;
    }

    cout << ans;
    return 0;
}
