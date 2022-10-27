#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;


int isPrime(int x){
    if(x < 2) return false;

    for(int i = 2; i <= x /2 ; ++i){
        if(x % i == 0) return 0;
    }

    return 1;
}


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    vi p(201);
    rep(i,201){
        p[i] = isPrime(i);
    }

    vector<int> j;
    reps(i,a,b+1){

        bool j2 = false;
        reps(j,c,d+1){
            if(p[i+j] > 0){
                j2 = true;
                break;
            }
        }
        j.push_back(j2);
    }

    fore(x,j){
        if(x == false){
            cout << "Takahashi";
            return 0;
        }
    }

    cout << "Aoki";
}
