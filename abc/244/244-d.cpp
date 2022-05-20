#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define npos string::npos
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;

int main(){
    char s1,s2,s3,t1,t2,t3;
    cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;

    if(
        s1 == t2 && s2 == t1 && s3 == t3 ||
        s1 == t1 && s2 == t3 && s3 == t2 ||
        s1 == t3 && s2 == t2 && s3 == t1
    ){
        cout << "No";
    } else {
        cout << "Yes";
    }
}