//
// Created by peng0 on 2021/9/8.
//
#include <iostream>

using namespace std;
int a[2000002];

int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> q;
        cout << a[q] << endl;
    }

    return 0;
}