//
// Created by peng0 on 2021/9/5.
//

#include <iostream>

long long dfs(long long n) {
    if (n == 1) return 1;
    return n * dfs(n - 1);
}
int main(){
    int n ;
    scanf("%d",&n);
    printf("%ld",dfs(n));
    return 0;
}