#include <iostream>
#include <string>

using namespace std;
int cost[2][2] = {{0, 0},
                  {0, 0}};
int dp[2][1000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    string src;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> cost[0][1] >> cost[1][0] >> src;
        int N = src.size();
        for (int i = 0; i <= N; ++i) {
            dp[0][i] = MAX;
            dp[1][i] = MAX;
        }
        if (src[0] == '?' || src[0] == 'C') dp[0][0] = 0;
        if (src[0] == '?' || src[0] == 'J') dp[1][0] = 0;

        for (int i = 1; i < N; i++) {
            if (src[i] == '?' || src[i] == 'C')
                dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + cost[1][0]);
            if (src[i] == '?' || src[i] == 'J')
                dp[1][i] = min(dp[0][i - 1], dp[1][i - 1] + cost[0][1]);
        }
        cout << "Case #" << tc << ": " << min(dp[0][N - 1], dp[1][N - 1]) << endl;
    }
    return 0;
}