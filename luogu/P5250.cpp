//
// Created by peng0 on 2021/9/22.
//
#include <iostream>
#include <set>
using namespace std;
int N, cmd, op;
set<int> g;
set<int>::iterator lwb, lbc;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> cmd >> op;
    if (cmd == 1) {
      if (!g.insert(op).second)
        cout << "Already Exist" << endl;
    } else {
      if (g.empty())
        cout << "Empty";
      else if (g.find(op) != g.end())
        cout << op, g.erase(g.find(op));
      else {
        lwb = lbc  = g.lower_bound(op);
        if (lwb == g.begin())
          cout << *lwb, g.erase(lwb);
        else if (lwb == g.end())
          cout << *(--lwb), g.erase(lwb);
        else if (*lwb - op < op - *(--lbc))
          cout << *(lwb), g.erase(lwb);
        else
          cout << *(lbc), g.erase(lbc);
      }
      cout << endl;
    }
  }
  return 0;
}