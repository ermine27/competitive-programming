#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using pii = pair<int,int>;


int judge(char a, char b){
    if(a == b) return -1;
    if(a == 'G') return (b == 'C') ? 0 : 1;
    if(a == 'C') return (b == 'P') ? 0 : 1;
    return (b == 'G') ? 0 : 1;
}

int main(){
    int n,m;
    cin >> n >> m;
    n *= 2;
    vector<pii> s(n);
    vector<vector<char>> a(n, vector<char>(m));

    rep(i, n){
        s[i] = make_pair(i,0);
        rep(j,m) cin >> a[i][j];
    }

    rep(i,m){
        for(int j = 0; j < n; j += 2){
            char c1 = a[s[j].first][i];
            char c2 = a[s[j+1].first][i];
            int jj = judge(c1,c2);
            if(jj >= 0) s[j+jj].second++;
        }

        sort(all(s), [](pii a, pii b){
            return a.second > b.second || a.second == b.second && a.first < b.first;
        });
    }

    rep(i,n) cout << s[i].first + 1 << endl;

}
