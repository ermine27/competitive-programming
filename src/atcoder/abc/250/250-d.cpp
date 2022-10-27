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

int main(){
    ll n;
    cin >> n;

    eratosthenes(ceil(cbrt(n)));

    ll ans = 0;

    fore(q, primes){
        ll p = min((ll)q-1, n / q / q / q);

        if(p == 0) break;

        int pi = 0;
        while(primes[pi] <= p) pi++;
        ans += pi;
    }

    cout << ans;
}
