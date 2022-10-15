/*
リファクタリング

サイクルの要素を2次元配列に持たず、できたサイクルから順次最小コストを計算していく
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
#define all(v) v.begin(), v.end()


int main(){
    int n;
    cin >> n;
    vi w(n), ord(n), t;
    rep(i,n) cin >> w[i];
    t = w;
    sort(all(t));

    rep(i,n){
        rep(j,n){
            if(w[i] == t[j]){
                ord[i] = j;
                break;
            }
        }
    }

    vector<bool> v(n);
    int vc = 0;
    int p = 0;
    int ans = 0;
    while(vc < n){
        vi row;
        while(v[p] == 0){
            row.push_back(w[ord[p]]);
            v[p] = 1;
            p = ord[p];
            ++vc;
        }

        ++p;
        int rsize = row.size();
        if(rsize < 2) continue;
        if(rsize == 2) ans += row[0] + row[1];
        if(rsize > 2){
            sort(all(row));
            int r1 = reduce(all(row)) + (rsize - 2) * row[0];
            int r2 = reduce(all(row)) + row[0] + (rsize + 1) * t[0];
            ans += min(r1,r2);
        }
    }

    cout << ans << endl;
    return 0;    
}
