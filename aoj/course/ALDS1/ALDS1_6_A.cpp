#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

int N;
vi A,B;

void CountingSort(vi &a, vi &b, int k){
    vi c(k+1);

    for(int j=1; j<=N; ++j) c[a[j]]++;
    for(int i=1; i<=k; ++i) c[i] += c[i-1];

    for(int j = N; j >= 1; --j){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

int main(){
    cin >> N;
    A.resize(N+1);
    rep(i,N) cin >> A[i+1];
    B = A;

    CountingSort(A, B, *max_element(A.begin(), A.end()));

    rep(i,N){
        if(i != 0) cout << ' ';
        cout << B[i+1];
    }
    cout << endl;

    return 0;
}
