#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int n,q;
    string s, s1, s2;
    cin >> n >> s >> q;
    s1 = s.substr(0,n);
    s2 = s.substr(n);
    bool sw = false;

    int ti,ai,bi;
    rep(i,q){
        cin >> ti >> ai >> bi;
        --ai; --bi;
        if(ti == 1){
            if(sw == false){
                if(ai < n){
                    if(bi < n) swap(s1[ai], s1[bi]);
                    else swap(s1[ai], s2[bi-n]);
                }else{
                    swap(s2[ai-n], s2[bi-n]);
                }

            } else {
                if(ai < n){
                    if(bi < n) swap(s2[ai], s2[bi]);
                    else swap(s2[ai], s1[bi-n]);
                }else{
                    swap(s1[ai-n], s1[bi-n]);
                }

            }
        }
        else sw = !sw;
    }

    cout << (sw ? s2 + s1 : s1 + s2);
}
