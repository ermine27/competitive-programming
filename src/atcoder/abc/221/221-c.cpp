#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    string s;
    cin >> s;
    s += ',';  // ,使う必要なかった。。
    int len = s.length();

    sort(all(s));

    ll ans = 0;
    do
    {
        int div = s.find(',');
        if(div == 0 || div == len-1) continue;
        ll a = stoll(s.substr(0,div));
        ll b = stoll(s.substr(div+1));
        chmax(ans, a*b);
    } while (next_permutation(all(s)));
    
    cout << ans;
}