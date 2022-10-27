/*
この問題の考え方

全てのiにおいて、
gcd(Ai, k) = 1
を満たす1以上M以下の整数kを列挙する
（gcd:最大公約数）

全ての要素に対して最大公約数が１になるKを求める

1つの要素についてgcd(Ai,k)=1となるのは、Aiとkの約数で共通する要素が1しかないことと同値である

つまり、全てのAiを素因数分解し、
該当する素数のn倍を全て除いたものがKになる


N,M <= 10^5 なので、答えの配列を作っておく（mapやsetでもいい）
Aを昇順でソートして、
順番N倍の値に対して答えの配列から消す（フラグを落とす）
この処理を毎回するとループが増えて計算量が大きいかもしれないので、ある約数diにおいての消し込みをしたかをメモ化する

スキップの回数を増やすには数列Aを昇順でソートしておくとよいが、実行時間制限的にそこまでシビアではなさそう

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;


vi divisor(int x){
    vi ans;
    for(int i = 1; i*i <= x; ++i){
        if(x % i == 0){
            ans.push_back(i);
            if(i * i != x){
                ans.push_back(x/i);
            }
        }
    }

    sort(all(ans));
    return ans;
}


int main(){
    int n,m,ai;
    cin >> n >> m;

    set<int> a,c,memo;
    rep(i,n){
        cin >>ai;
        a.insert(ai);
    }

    rep(i,m) c.insert(i+1);
    
    fore(x,a){
        vi d = divisor(x);

        fore(xx,d){
            if(memo.count(xx)) continue;
            if(xx == 1) continue;
            memo.insert(xx);
            int k = 1;
            while(xx*k <= m){
                c.erase(xx*k);
                ++k;
            }
        }
    }  

    c.insert(1);

    cout << c.size() << endl;
    fore(x,c){
        cout << x << endl;
    }
}
