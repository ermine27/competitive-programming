#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using vi = vector<int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int n,m,a,b;
    vector<pair<int,int>> np,mp;
    cin >> n >> m;

    rep(i,m){
        cin >> a >> b;
        np.push_back(make_pair(a-1,b-1));
    }
    rep(i,m){
        cin >> a >> b;
        mp.push_back(make_pair(a-1,b-1));
    }

    sort(all(np));

    vector<int> p(n);
    rep(i,n) p[i] = i;

    do{
        vector<pair<int,int>> tp;
        int t1,t2;
        rep(i,m){
            t1 = p[mp[i].first];
            t2 = p[mp[i].second];
            if(t1>t2) swap(t1,t2);
            tp.push_back(make_pair(t1, t2));
        }
        sort(all(tp));
        if(np == tp){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(all(p)));

    cout << "No" << endl;
    return 0;
}
