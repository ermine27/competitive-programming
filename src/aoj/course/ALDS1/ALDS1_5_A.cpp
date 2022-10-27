/*
分割統治法→再帰で解く

bit全探索の処理は、2^20 = 1048575 --> 10^6 と多いので、
先に全てのパターンで出来る数値を求めておく。
その配列を使って、mが作れるかを判定していく。

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;


int N;
vi A;

bool solve(int val, int cur){
    if(val == 0) return true;
    if(cur == N) return false;

    if(solve(val - A[cur],cur+1) || solve(val, cur+1)) return true;
    else return false;
    
}

int main(){
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    int Q;
    cin >> Q;
    vi M(Q);
    rep(i,Q) cin >> M[i];

    rep(i,Q){
        if(solve(M[i], 0)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;    
}

