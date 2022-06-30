#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int INF = 1e9;


int h = 0;
int a[2000000];

void heapIncreaseKey(int i, int key){
    if(key < a[i]){
        return;
    }
    a[i] = key;
    while(i > 1 && a[i/2] < a[i]){
        swap(a[i], a[i/2]);
        i = i/2;
    }

}

void insert(int key){
    ++h;
    a[h] = -INF;
    heapIncreaseKey(h, key);
}

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

int extract(){
    int max;

    if(h<1){
        return -1;   
    }

    max = a[1];
    a[1] = a[h];
    --h;
    maxHeapify(1);

    return max; 
}

int main(){
    string cmd;
    int k;

    while(cin >> cmd && cmd != "end"){
        if(cmd == "insert"){
            cin >> k;
            insert(k);

        } else {
            cout << extract() << endl;
        }
    }

    return 0;
}
