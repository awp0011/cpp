//
// Created by peng0 on 2021/9/22.
//
#include "iostream"
#include "map"
using namespace std;
map<int, int> m[200005];
int N, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  string a, b;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    int va = (a[0] - 'A') * 1000 + a[1];
    int vb = (b[0] - 'A') * 1000 + b[1];
    if (va != vb)
      ans += m[vb][va];
    m[va][vb]++;
  }
  cout << ans << endl;
  return 0;
}
