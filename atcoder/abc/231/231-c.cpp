#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using ll = long long;


int binarySearch(vi &a, int v){
    int high = a.size();
    int low = -1;
    int mid;

    while(high - low > 1){
        mid = (high + low) / 2;
        if(a[mid] >= v) high = mid;
        else low = mid;
    }
    return high;
}

int main(){
    int n,q,qi,ans;
    cin >> n >> q;
    vi a(n), x(q);

    rep(i,n) cin >> a[i];
    sort(all(a));
    rep(i,q){
        ans = 0;
        cin >> qi;

        ans = binarySearch(a,qi);
        cout << n - ans << endl;
    }

}
