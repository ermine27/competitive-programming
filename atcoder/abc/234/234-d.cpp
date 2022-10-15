/*

1,2,...Nの並び替えと言っているので、要素の重複はない

N <= 5*10^5　なので毎回二分探索＋ソートする方法だと、計算量が足りない。
ソートを最初の1回だけにして、毎回二分探索＋適切な位置にinsertしていく方法でも間に合わない。
（vectorのinsertやeraseは遅い）

優先度付きキュー(priority_queue) を使って解く。

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;


int main(){
    int n,k;
    cin >> n >> k;
    vi p(n);
    rep(i,n) cin >> p[i];

    priority_queue<int, vi, greater<int>> q;
    rep(i,n){
        q.push(p[i]);
        if(q.size() > k){
            q.pop();
        }
        if(q.size() >= k){
            cout << q.top() << endl;
        }
    }

    return 0;    
}
