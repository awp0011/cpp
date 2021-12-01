#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int>::iterator vi;
//using vi = vector<int>::iterator ;
int T, N, Q, ret;
vector<int> ans;

inline int query(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << endl;
    cin >> ret;
    if (ret == -1) exit(0);
    return ret;
}

vi ternary_search(vi s, vi e, int key) {
    if (s >= e) return s;
    if (s + 1 == e) {
        if (s == ans.begin())
            return ternary_search(s, e + 1, key);
        else
            return ternary_search(s - 1, e, key);
    }
    vi t1 = s + (e - s) / 3, t2 = s + (e - s) * 2 / 3;
    query(*t1, *t2, key);

    if (ret == *t1)
        return ternary_search(s, t1, key);
    else if (ret == *t2)
        return ternary_search(t2 + 1, e, key);
    else
        return ternary_search(t1 + 1, t2, key);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T >> N >> Q;
    for (int tc = 1; tc <= T; tc++) {
        query(1, 2, 3);
        if (ret == 1)
            ans = {2, 1, 3};
        else if (ret == 2)
            ans = {1, 2, 3};
        else
            ans = {1, 3, 2};

        // sort
        for (int i = 4; i <= N; i++) {
            auto idx = ternary_search(ans.begin(), ans.end(), i);
            ans.insert(idx, i);
        }
        // output answer
        for (auto num: ans) cout << num << ' ';
        cout << endl;
        cin >> ret;
        if (ret == -1) exit(0);
        ans.clear();
    }

    return 0;
}
