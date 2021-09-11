//
// Created by peng0 on 2021/9/8.
//
#include <iostream>

using namespace std;
int p[5005], cnt[5005];

int find(int c) {
    if (p[c] == c)return c;
    return p[c] = find(p[c]);
}

void group(int c1, int c2) {
    int p1 = find(c1);
    int p2 = find(c2);
    if (p1 == p2)return;
    if (cnt[p1] > cnt[p2]) {
        p[p2] = p1;
    } else {
        p[p1] = p2;
        if (cnt[p1] == cnt[p2]) cnt[p2]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        cnt[i] = 1;
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        group(a, b);
    }
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << ((find(a) == find(b)) ? "Yes" : "No") << endl;
    }

    return 0;
}