#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define fore(x,a) for(auto& (x):(a))
using ll = long long;


ll n;

ll dfs(string &s){
    ll ans = 0;
    vector<char> c357 = {'3', '5', '7'};

    if(s.size() > 0 && stoll(s) > n){
        return 0;
    }

    bool ok = true;
    fore(c, c357){
        if(s.find(c) == string::npos) ok = false;
    }
    if(ok) ++ans;

    fore(c, c357){
        s.push_back(c);
        ans += dfs(s);
        s.pop_back();
    }

    return ans;
}

int main() {
    cin >> n;

    string s = "";
    cout << dfs(s);

}