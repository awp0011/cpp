//
// Created by peng0 on 2021/9/5.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, m;

double avg(double scre[]) {
    double minV = 10, maxV = 0;
    for (int i = 1; i <= m; ++i) {
        scre[0] += scre[i];
        minV = min(minV, scre[i]);
        maxV = max(maxV, scre[i]);
    }
    scre[0] -= minV + maxV;
    return scre[0] / (m - 2);
}

int main() {
    scanf("%d %d", &n, &m);
    double s[m + 1];
    double maxS = 0;
    for (int i = 0; i < n; ++i) {
        s[0] = 0;
        for (int j = 1; j <= m; ++j) scanf("%lf", &s[j]);
        maxS = max(maxS, avg(s));
    }
    printf("%.2lf\n", maxS);

    return 0;
}