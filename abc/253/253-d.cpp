#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll n, a, b, c;
    cin >> n >> a >> b;
    c = lcm(a,b);
    ll sumn, suma, sumb, sumc;
    ll maxa, maxb, maxc;

    sumn = n * (n + 1) / 2;
    maxa = n / a;
    maxb = n / b;
    maxc = n / c;

    suma = maxa * (maxa + 1) / 2;
    sumb = maxb * (maxb + 1) / 2;
    sumc = maxc * (maxc + 1) / 2;

    suma *= a;
    sumb *= b;
    sumc *= c;

    cout << sumn - suma - sumb + sumc;
}
