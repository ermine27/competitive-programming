/*
Sの最大が30000なので、Sから全探索して暗証番号を見つけようとすると計算量が足りなくなる。
暗証番号の種類の最大値に着目すると、3桁なので1000しかない。
000から999までの暗証番号が作れるかを順にチェックしていくことで時間内に計算が完了する。

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(i,1000){
        vector<char> c(3);
        c[0] = (i / 100) + '0';
        c[1] = ((i % 100) / 10) + '0';
        c[2] = (i % 10) + '0';

        int j = 0;
        int u = 0;
        while(j < n){
            if(s[j] == c[u]) ++u;
            if(u == 3){
                ++ans;
                break;
            }
            ++j;
        }
    }

    cout << ans;
}
