//
// Created by peng0 on 2021/9/6.
//

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int T, N, M, p, c, m[8], cur_idx, nex_idx, preStatus, setStatus, flen, score;

//f[i][0] 前接状态；f[i][1] 后置状态，f[i][2] 碎片长度;f[i][4] 碎片分数
int f[8][4] = {{0, 0, 0, 0},
               {0, 0, 1, 0}, //碎片1，初始化时使用
               {0, 2, 2, 0}, //碎片2
               {2, 0, 2, 0}, //碎片3
               {0, 1, 2, 0}, //碎片4
               {1, 0, 2, 0}, //碎片5
               {2, 2, 3, 0}, //碎片6
               {1, 1, 3, 0}};//碎片7
long long ans, dp[3][500005];

//读优化
inline int read() {
    int num = 0;
    char c;
    bool flag = false;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
    if (c == '-') flag = true;
    else
        num = c - '0';
    while (isdigit(c = getchar()))
        num = num * 10 + c - '0';
    return (flag ? -1 : 1) * num;
}

int main() {
    T = read();
    for (int tc = 1; tc <= T; ++tc) {
        N = read(), M = read();
        for (int i = 0; i < M; ++i) {
            p = read(), c = read();
            m[i] = p;
            f[p][3] = c;
        }
        //初始化，使用碎片1铺满整个四边形
        dp[0][0] = dp[1][0] = dp[2][0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[0][i] = dp[0][i - 1] + (f[1][3] << 1);
            dp[1][i] = dp[2][i] = dp[0][i - 1] + f[1][3];
        }
        //
        for (int i = 1; i <= N; i++) {
            for (int j = 2; j <= M; ++j) {
                preStatus = f[m[j]][0];
                setStatus = f[m[j]][1];
                flen = f[m[j]][2];
                score = f[m[j]][3];
                if (preStatus == 0) {//前接状态为0 需要使用i-1的0状态
                    cur_idx = i - 1;
                    nex_idx = i + flen;
                } else {
                    cur_idx = i;
                    nex_idx = i + flen - 1;
                }
                if (nex_idx > N) continue;
                if (dp[setStatus][nex_idx] < dp[preStatus][cur_idx] + score)
                    dp[setStatus][nex_idx] = dp[preStatus][cur_idx] + score;
            }
        }
        ans = 0;
        ans = max(ans, dp[0][N]);
        ans = max(ans, dp[1][N] + f[1][3]);
        ans = max(ans, dp[2][N] + f[1][3]);
        printf("#%d %lld\n", tc, ans);
    }
    return 0;
}