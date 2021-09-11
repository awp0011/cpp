//
// Created by peng0 on 2021/9/5.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, nx;

bool isPrime(int n) {
    int end = sqrt(n);
    for (int i = 2; i <= end; ++i) {
        if (n % i == 0)return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nx);
        if (nx == 1) continue;
        else if (isPrime(nx)) printf("%d ", nx);
    }
    return 0;
}