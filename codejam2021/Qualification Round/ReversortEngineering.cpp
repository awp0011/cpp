#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int val[103];
vector<int> d;

int main() {
    int T, N, C, maxC, minC;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> C;
        maxC = (((N + 1) * N) >> 1) - 1;
        minC = N - 1;
        if (C > maxC || C < minC) {
            cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
            continue;
        }
        //当有多个答案时，可以输入任何一个，都算正确
        for (int i = 1, sw = C - N + 1; i < N; ++i) {
            val[i] = 0;
            if (sw > 0) {
                val[i] = min(sw, N - i);
                sw -= val[i];
            }
            val[i]++;
        }
        d.push_back(0);
        d.push_back(N);
        for (int i = N - 1; i > 0; i--) {
            reverse(d.begin() + 1, d.begin() + val[i] - 1);
            d.insert(d.begin() + val[i], i);
        }
        cout << "Case #" << tc << ":";
        for (int i = 1; i <= N; ++i) cout << ' ' << d[i];
        cout << endl;
        d.clear();
    }
    return 0;
}



