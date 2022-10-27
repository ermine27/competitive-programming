#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

int main(){
    const int mod = 1000000007;
    int n,m;
    cin >> n >> m;
    map<int,vi> mp;
    int ai,bi;
    rep(i,m){
        cin >> ai >> bi;
        mp[ai].push_back(bi);
        mp[bi].push_back(ai);
    }

    vi dist(n+1,-1);
    vi cnt(n+1,0);
    dist[1] = 0;
    cnt[1] = 1;

    queue<int> q;
    q.push(1);

    while(q.empty() == false){
        int cur = q.front();
        q.pop();

        fore(x, mp[cur]){
            if(dist[x] == -1){
                dist[x] = dist[cur] + 1;
                q.push(x);
            }

            if(dist[cur] + 1 == dist[x]){
                cnt[x] += cnt[cur];
                cnt[x] %= mod;
            }
        }
    }

    cout << cnt[n];
    return 0;    
}
