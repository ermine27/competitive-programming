#include <bits/stdc++.h>
using namespace std;

void printSequence(vector<int> &a, int n) {
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(vector<int> &a, int n) {
    for (int i = 1; i < n; ++i) {
        int v = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = v;
        printSequence(a, n);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    printSequence(a, n);
    insertionSort(a, n);

    return 0;
}
