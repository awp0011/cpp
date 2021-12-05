#include <iostream>

using namespace std;
struct bigint {
    int len;
    int arr[200];
} pre, cur;
int T, N, nx, m, ans;

inline void int2arr(int n, bigint it) {
    int pos = 0;
    fill(it.arr, it.arr + 200, 0);
    while (n > 0) {
        it.arr[pos] = n % 10;
        pos++
        n /= 10;
    }
    it.len = pos;
}

inline void copy2pre() {
    copy(cur.arr, cur.arr + cur.len - 1, pre.arr);
    pre.len = cur.len;
}

inline void shift(int n) {
    for (int i = cur.len - 1; i >= n; --i) cur.arr[i + n] = cur.arr[i];
    for (int i = 0; i < n; ++i) cur.arr[i] = 0;
    cur.len += n;
}

inline bool append(int n) {
    int carry = 0, idx = 0;
    while (idx < n && pre.arr[idx] == cur.arr[idx]) idx++;
    if (idx < n) {
        cur.arr[idx] = pre.arr[idx] + 1;
        carry = cur.arr[idx] / 10;
        cur.arr[idx] %= 10;
        idx++;
    }
    while (idx < n) {
        cur.arr[idx] = pre.arr[idx] + carry;
        carry = cur.arr[idx] / 10;
        cur.arr[idx] %= 10;
        idx++;
    }
    return carry;
}

inline int append() {
    int min_v = 0;
    if (cur.len <= pre.len) {
        min_v = pre.len - cur.len;
        shift(min_v);
        if (append(min_v)) {//再多1位
            reset(min_v);
            shift(++min_v);
        }
    }
    return min_v;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> N;
        cin >> nx;
        int2arr(nx, pre);
        for (int i = 1; i < N; ++i) {
            cin >> nx;
            int2arr(nx, cur);
            m = append();
            copy2pre();
            ans += m;
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}