/*
双方向リストのlistコンテナがあるけど、
この問題の場合は、複数必要になるのでそれぞれのfrontとbackを持たせるだけで良さそう

計算量は、問題文の制約で
　3 x の形式のクエリで出力する電車の番号の個数の合計は 10 ^6 以下
と記されているので、愚直に先頭を探しにいく方法で足りる
また、
　Q <= 2 * 10^5 
という制約からも計算量は時間内に収まるはず。

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))
using vi = vector<int>;


int main(){
    int n,q;
    cin >> n >> q;

    vi front(n+1,-1), back(n+1,-1);

    rep(i,q){
        int ci,xi,yi;
        cin >> ci >> xi;
        if(ci != 3){
            cin >> yi;
        }

        if(ci == 1){
            back[xi] = yi;
            front[yi] = xi;
        }
        if(ci == 2){
            back[xi] = -1;
            front[yi] = -1;
        }
        if(ci == 3){
            while(front[xi] != -1){
                xi = front[xi];
            }

            vi train;
            train.push_back(xi);
            while(back[xi] != -1){
                xi = back[xi];
                train.push_back(xi);
            }

            cout << train.size();
            fore(x, train) cout << ' ' << x;
            cout << endl;
        }
    }

    return 0;    
}
