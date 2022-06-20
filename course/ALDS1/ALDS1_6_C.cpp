#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

const int INF = 1000000000;

struct card{
    char suit;
    int number;
};

void merge(vector<card> &c, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    vector<card> subleft, subright;
    rep(i,n1) subleft.push_back(c[i]);
    rep(i,n2) subright.push_back(c[mid+i]);

    rep(i, n1){
        subleft[i] = c[left+i];
    }
    rep(i, n2){
        subright[i] = c[mid+i];
    }
    subleft[n1].number = INF;
    subright[n2].number = INF;

    int i = 0;
    int j = 0;

    for(int k = left; k < right; ++k){
        if(subleft[i].number <= subright[j].number){
            c[k] = subleft[i];
            ++i;
        } else{
            c[k] = subright[j];
            ++j;
        }
    }

    return;
}


void mergeSort(vector<card> &c, int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(c, left, mid);
        mergeSort(c, mid, right);
        merge(c, left, mid, right);
    }
    return;
}


int partition(vector<card> &c, int p, int r){
    int x = c[r].number;
    int i = p - 1;
    for(int j = p; j < r; ++j){
        if(c[j].number <= x){
            ++i;
            swap(c[i], c[j]);
        }
    }
    swap(c[i+1], c[r]);

    return i+1;
}


void quickSort(vector<card> &c, int p, int r){
    if(p < r){
        int q = partition(c, p, r);
        quickSort(c, p, q-1);
        quickSort(c, q+1, r);
    }
}

int main(){
    int N;
    cin >> N;
    vector<card> a(N), b(N);
    rep(i,N) cin >> a[i].suit >> a[i].number;
    b = a;

    mergeSort(a, 0, N);

    quickSort(b, 0, N-1);

    bool ok = true;
    rep(i, a.size()){
        if(a[i].suit != b[i].suit) ok = false;
    }
    cout << (ok ? "Stable" : "Not stable") << endl;

    rep(i,b.size()){
        cout << b[i].suit << ' ' << b[i].number << endl;
    }

    return 0;    
}
