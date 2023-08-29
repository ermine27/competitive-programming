/*
二分グラフの最大マッチング
Ford-Fullkerson法

参考
https://algo-logic.info/bipartite-matching/
*/

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

template <typename T>
struct Edge {
    int rev, from, to;
    T cap, original_cap;
    Edge(int r, int f, int t, T c) : rev(r), from(f), to(t), cap(c), original_cap(c) {}
};

template <typename T>
struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    const T size() const { return G.size(); }
    Edge<T>& redge(Edge<T> e) { return G[e.to][e.rev]; }
    void add_edge(int from, int to, T cap) {
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size() - 1, to, from, 0));
    }
};

template <typename T>
struct FordFulkerson {
    const T INF = 1e9;
    vector<int> used;

    FordFulkerson(){};
    T dfs(Graph<T>& G, int v, int t, T f) {
        if (v == t)
            return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(Graph<T>& G, int s, int t) {
        T flow = 0;
        while (true) {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);
            if (f == 0) {
                return flow;
            } else {
                flow += f;
            }
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    Graph<int> g(n * 2 + 2);
    rep(i, n) {
        g.add_edge(0, i + 1, 1);
        g.add_edge(n + i + 1, n * 2 + 1, 1);
    }
    rep(i, n) {
        rep(j, n) {
            char c;
            cin >> c;
            if (c == '#') {
                g.add_edge(i + 1, n + j + 1, 1);
            }
        }
    }
    FordFulkerson<int> ff;
    int ans = ff.max_flow(g, 0, n * 2 + 1);
    cout << ans << endl;

    return 0;
}
