#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll n,a,b,p,q,r,s;
    cin >> n >> a >> b >> p >> q >> r >> s;

    ll y1, y2;
    char c;
    for(ll i = p; i <= q; ++i){
        y1 = -i + b + a;
        y2 = i + b - a;

        for(ll j = r; j <= s; ++j){
            if(j == y1 || j == y2) c = '#';
            else c = '.';
            cout << c;
        }
        cout << endl;
    }
}
