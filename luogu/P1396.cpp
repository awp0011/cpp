#include <algorithm>
#include <iostream>

using namespace std;

int n, m, s, t, ans, p[10005]{};
struct edge {
  int x, y, val;
} d[20005];
inline bool comp2(edge a, edge b) { return a.val < b.val; }
inline int find(int c) {
  if (p[c] == c)
    return c;
  return p[c] = find(p[c]);
}

inline bool group(int c1, int c2) {
  int p1 = find(c1);
  int p2 = find(c2);
  if (p1 != p2) {
    p[p1] = p2;
    return true;
  } else {
    return false;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; i++)
    p[i] = i;
  for (int i = 0; i < m; i++)
    cin >> d[i].x >> d[i].y >> d[i].val;

  sort(d, d + m, comp2);
  for (int i = 0; i < m; i++) {
    if (group(d[i].x, d[i].y))
      ans = d[i].val;
    if (find(s) == find(t))
      break;
  }
  cout << ans << endl;

  return 0;
}