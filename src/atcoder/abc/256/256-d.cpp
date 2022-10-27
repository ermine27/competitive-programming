#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& x:a)
#define fore2(k,v,a) for(auto& [k,v] : a)
#define all(v) v.begin(), v.end()
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;


int main(){
    int n;
    cin >> n;
    vector<pii> s;
    rep(i,n){
        int li,ri;
        cin >> li >> ri;
        s.push_back(make_pair(li,0));
        s.push_back(make_pair(ri,1));
    }
    sort(all(s));

    int lc = INF;
    int cnt = 0;

    fore2(v,c,s){
        if(c == 0){
            chmin(lc, v);
            ++cnt;
        } else {
            --cnt;
            if(cnt == 0){
                cout << lc << ' ' << v << endl;
                lc = INF;
            }
        }
    }

    // 以下のように書くと、変数(lc)の利用をなくせる

    // int cnt = 0;
    // fore2(v,c,s){
    //     if(c == 0){
    //         if(cnt == 0) cout << v << ' ';
    //         ++cnt;
    //     } else {
    //         --cnt;
    //         if(cnt == 0) cout << v << endl;
    //     }
    // }


    return 0;
}
