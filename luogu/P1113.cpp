//
// Created by peng0 on 2021/9/11.
//
#include "iostream"
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> g[10005];
queue<int> que;
int n, ans, len[10005]{}, dp[10005]{}, inDep[10005]{};
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  /*  for (int i = 1; i < n; ++i)
      dp[i] = 0;*/
  int nx, l, pre;
  for (int i = 0; i < n; ++i) {
    cin >> nx >> l >> pre;
    len[nx] = l;
    while (pre > 0) {
      g[pre].push_back(nx);
      cin >> pre;
      inDep[nx]++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (inDep[i] == 0) {
      que.push(i);
      dp[i] += len[i];
    }
  }
  ans = 0;
  while (!que.empty()) {
    int u = que.front();
    for (int v : g[u]) {
      if (dp[v] < dp[u] + len[v]) {
        dp[v] = dp[u] + len[v];
        ans = max(ans, dp[v]);
      }
      if (--inDep[v] == 0)
        que.push(v);
    }
    que.pop();
  }
  cout << ans << endl;
  return 0;
}
