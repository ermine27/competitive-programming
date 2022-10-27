#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define per(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define perf(i,n) for(int i = (int)(n); i > 0; --i)
using vi = vector<int>;

int h;
vi a;

void maxHeapify(int i){
    int l = 2*i;
    int r = 2*i+1;
    int largest;

    if(l <= h && a[l] > a[i]){
        largest = l;
    } else {
        largest = i;
    }

    if(r <= h && a[r] > a[largest]){
        largest = r;
    }

    if(largest != i){
        swap(a[i], a[largest]);
        maxHeapify(largest);
    }
}

int main(){
    cin >> h;
    a.resize(h+1);
    repf(i,h) cin >> a[i];

    perf(i,h/2){
        maxHeapify(i);
    }

    repf(i,h) cout << ' ' << a[i];
    cout << endl;

    return 0;
}
