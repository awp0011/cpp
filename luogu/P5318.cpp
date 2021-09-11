//
// Created by peng0 on 2021/9/11.
//
#include <vector>
#include <queue>
#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> g[100005];
bitset<100005> vis;
queue<int> que;

inline void bfs(int s) {
    while (que.size())que.pop();//相当于clear
    vis.reset();
    que.push(s);
    vis.set(s);
    while (que.size()) {
        int u = que.front();
        cout << u << ' ';
        vis.set(u);
        que.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis.test(v))
                vis.set(v), que.push(v);
        }
    }
}

inline void dfs(int s) {
    vis.set(s);
    cout << s << ' ';
    for (int i = 0; i < g[s].size(); ++i) {
        int v = g[s][i];
        if (!vis.test(v))
            dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << endl;
    bfs(1);
    return 0;
}