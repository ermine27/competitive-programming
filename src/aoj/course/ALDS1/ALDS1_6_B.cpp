#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

vi a;

int partition(int p, int r){
    int x = a[r];
    int i = p - 1;
    for(int j = p; j < r; ++j){
        if(a[j] <= x){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);

    return i+1;
}

int main(){
    int N;
    cin >> N;
    a.resize(N);
    rep(i,N) cin >> a[i];

    int q = partition(0, N-1);

    rep(i,N){
        if(i != 0) cout << ' ';

        if(i == q) cout << '[' << a[i] << ']';
        else cout << a[i];
    }
    cout << endl;

    return 0;    
}
