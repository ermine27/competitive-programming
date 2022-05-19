// WA　pow関数で大きい値を使うところで誤差が生じる

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll c = 998244353;

int main(){
    ll n;
    cin >> n;

    ll f = 0;
    string ns = to_string(n);

    for(int i = ns.size()-1; i >= 0; --i){
        ll t;
        if(i == 0) t = n - pow(10,ns.size()-1) + 1;
        else t = pow(10,ns.size()-i-1) * 9;

        ll t1 = t % c;
        ll t2 = (t+1) % c;
        t = (t1*t2/2) % c;
        f += t;

        f %= c;
    }

    cout << f;
}
