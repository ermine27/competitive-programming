#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;


int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vi m(n+1);
    rep(i, k){
        int ai;
        cin >> ai;
        m[ai] = 1;
    }

    repf(i,q){
        int qi, cnt = 0, tar;
        cin >> qi;

        repf(i,n){
            if(m[i]){
                ++cnt;
                if(cnt == qi){
                    tar = i;
                    break;
                }
            }
        }

        if(tar < n && m[tar+1] == 0){
            m[tar] = 0;
            m[tar+1] = 1;
        }
    }

    int cnt = 0;
    repf(i,n){
        if(m[i]){
            if(cnt != 0){
                cout << ' ';
            }
            ++cnt;
            cout << i;
        }
    }

    return 0;
}
