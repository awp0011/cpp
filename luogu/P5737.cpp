//
// Created by peng0 on 2021/9/5.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int x, y, cnt, yyyy[2000];

bool isleep(int n) {
    if (n % 400 == 0) return true;
    if (n % 100 == 0)return false;
    return n % 4 == 0;
}

int main() {
    scanf("%d %d", &x, &y);
    for (int i = x; i <= y; ++i) {
        if (isleep(i)) {
            yyyy[cnt] = i;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d ", yyyy[i]);
    }
    return 0;
}