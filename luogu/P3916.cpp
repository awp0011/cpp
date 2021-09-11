//
// Created by peng0 on 2021/9/11.
//
#include <algorithm>
#include <iostream>
#include <vector>
#define MaxN 100005

using namespace std;

int n, m, dp[MaxN]{};
vector<int> g[MaxN];

inline void dfs(int u) {
  dp[u] = max(dp[u], u);
  for (int v : g[u]) {
    if (dp[v] < dp[u]) {
      dp[v] = dp[u];
      dfs(v);
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  int u, v;
  //按题目来每次考虑每个点可以到达点编号最大的点，不如考虑较大的点可以反向到达哪些点
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    // g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (dp[i] == 0)
      dfs(i);
  }
  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << ' ';
  }
  return 0;
}