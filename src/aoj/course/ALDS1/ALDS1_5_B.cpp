#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;


const int INF = 1000000000;
int N;
int cnt = 0;


void merge(vi &a, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    vi subleft, subright;
    rep(i,n1) subleft.push_back(a[i]);
    rep(i,n2) subright.push_back(a[mid+i]);

    rep(i, n1){
        subleft[i] = a[left+i];
    }
    rep(i, n2){
        subright[i] = a[mid+i];
    }
    subleft[n1] = INF;
    subright[n2] = INF;

    int i = 0;
    int j = 0;

    for(int k = left; k < right; ++k){
        ++cnt;

        if(subleft[i] <= subright[j]){
            a[k] = subleft[i];
            ++i;
        } else{
            a[k] = subright[j];
            ++j;
        }
    }

    return;
}


void mergeSort(vi &a, int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
    return;
}

int main(){
    cin >> N;
    vi S(N);
    rep(i, N) cin >> S[i];

    mergeSort(S, 0, N);

    rep(i,N){
        if(i != 0) cout << ' ';
        cout << S[i];
    }
    cout << endl << cnt << endl;

    return 0;    
}
