#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

int main(){
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    map<int,int> m;
    rep(i,N) a[i] = i+1;
    rep(i,N){
        m[i+1] = i;
    }

    int xi;
    rep(i,Q){
        cin >> xi;
        int xa = m[xi];

        if(xa == N-1){

            int mi = m[xi];
            int ai2 = a[mi-1];
            int mi2 = m[ai2];
            swap(a[mi], a[mi2]);

            m[xi] = mi2;
            m[ai2] = mi;

        } else {

            int mi = m[xi];
            int ai2 = a[mi+1];
            int mi2 = m[ai2];
            swap(a[mi], a[mi2]);

            m[xi] = mi2;
            m[ai2] = mi;

        }

    }

    rep(i,N){
        if(i != 0) cout << ' ';
        cout << a[i];
    }

    return 0;
}
