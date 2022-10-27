#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;

vi memo(50, -1);

int fibonacci(int x) {
    if (x <= 1) return 1;
    if (memo[x] > 0) return memo[x];

    int a = fibonacci(x - 1) + fibonacci(x - 2);
    memo[x] = a;
    return a;
}

int main() {
    int n;
    cin >> n;
    memo[0] = memo[1] = 1;

    cout << fibonacci(n) << endl;
    return 0;
}
