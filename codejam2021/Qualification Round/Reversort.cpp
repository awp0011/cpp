#include <algorithm>
#include <iostream>

using namespace std;
int d[100];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> d[i];
        }
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            int j = min_element(d + i, d + N + 1) - d;
            ans += (j - i) + 1;
            reverse(d + i, d + j + 1);
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
