#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


// dequeを使わずに解く
int main(){
    string s;
    int k, len;
    cin >> s >> k;
    len = s.length();

    int ans = 0, a = 0;
    int l = 0;
    int u = k;

    rep(i,len){
        ++a;
        if(s[i] == '.'){
            --u;
            if(u < 0){
                int k = l;
                // 左端を次の.までをスキップしたい。
                // まず次の.までの間にあるXをスキップ
                // 同時に数えていたaの値もデクリメント
                while(s[k] == 'X'){
                    ++k;
                    --a;
                }
                // ここで次の.をスキップ
                ++k;
                --a;
                // 新しい左端を更新
                l = k;

            }
        }

        chmax(ans,a);
    }

    cout << ans;
    return 0;
}
