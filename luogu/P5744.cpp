//
// Created by peng0 on 2021/9/8.
//
#include <iostream>

using namespace std;
//ios::sync_with_stdio(false);
struct stu {
    string name;
    int age, score;
} a[1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name >> a[i].age >> a[i].score;
        a[i].age++;
        a[i].score *= 6;
        a[i].score /= 5;
        if (a[i].score > 600)a[i].score = 600;
        cout << a[i].name << " " << a[i].age << " " << a[i].score << endl;
    }
    return 0;
}
