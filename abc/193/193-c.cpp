#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

int main(){
    ll n, nsq;
    cin >> n;
    nsq = sqrt(n);

    set<ll> ct;
    for(int i = 2; i <= nsq; ++i){
        for(int j = 2; ; ++j){
            ll a = pow(i,j);

            if(a > n) break;
            if(pow(i,j) <= n) ct.insert(a);
        }
    }
    
    cout << n - ct.size();
}