#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    int n,ai;
    cin >> n;
    int ns = pow(2,n);
    vector<pair<int,int>> a;
    rep(i, ns){
        cin >> ai;
        a.push_back(make_pair(i+1,ai));
    }

    rep(i,n-1){
        vector<pair<int,int>> b;
        rep(j,a.size()/2){
                b.push_back( a[j*2].second > a[j*2+1].second ? a[j*2] : a[j*2+1] );
        }
        a = b;
    }

    cout << (a[0].second > a[1].second ? a[1].first : a[0].first);
}
