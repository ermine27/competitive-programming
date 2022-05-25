#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()

vi primes;

// 素数列挙（エラストテネスの篩）
void eratosthenes(int x){
    set<int> numbers;
    for(int i = 2; i <= x; ++i) numbers.insert(i);

    for(int i = 2; i * i < x; ++i){
        if(numbers.count(i)){
            for(int j = i * 2; j <= x; j += i){
                numbers.erase(j);
            }
        }
    }

    for(int x : numbers) primes.push_back(x);
}

// p * q^3 がlong long型の値を超える場合の考慮
ll f(ll p, ll q){
    double est;
    est = (double)p * q * q * q;
    return min(est, 9e18);
}

int main(){
    ll n;
    cin >> n;

    eratosthenes(ceil(cbrt(n)));

    ll ans = 0;

    rep(p, primes.size()-1){
        reps(q, p+1, primes.size()){
            if(f(primes[p], primes[q]) <= n) ++ans;
            else break;
        }
    }

    cout << ans;
}
