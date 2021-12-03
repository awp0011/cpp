#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const int QC = 10000;
const int PC = 100;

struct info {
    int idx;
    int cnt;
    double lvl;
    double w;
} qs[QC + 5], ps[PC + 2];

double prob[QC + 5];
char str[PC + 2][QC + 2];

inline bool cmp(info x, info y);

inline void get_rand(int size);

inline void set_peo_level();

inline void set_qst_level();

inline double sigmoid(double x);

inline int judge();

int main() {

    //freopen("C:\\Users\\peng0\\Downloads\\cheating_detection_sample_ts1_input.txt", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T, P, ans;
    cin >> T >> P;
    for (int tc = 1; tc <= T; tc++) {
        //初始化 问题
        for (int j = 0; j < QC; j++) {
            qs[j].idx = j;
            qs[j].lvl = 0;
            qs[j].cnt = 0;
            qs[j].w = 0;
        }
        // read case
        for (int i = 0; i < PC; i++) {
            cin >> str[i];
            ps[i].idx = i;
            ps[i].lvl = 0;
            ps[i].cnt = 0;
            ps[i].w = 0;
            for (int j = 0; j < QC; j++) {
                if (str[i][j] == '1')
                    ps[i].cnt++;
                else
                    qs[j].cnt++;
            }
        }
        //排序
        sort(ps, ps + PC, cmp);
        sort(qs, qs + QC, cmp);
        //指定人的skill level
        set_peo_level();
        //指定题目difficult level
        set_qst_level();

        ans = judge();
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}

inline double get_rand() { return (double) rand() / RAND_MAX * 6 - 3; }

inline bool cmp(info x, info y) { return x.cnt < y.cnt; }

inline void set_peo_level() {
    for (int i = 0; i < PC; i++) prob[i] = get_rand();
    sort(prob, prob + PC);
    for (int i = 0; i < PC; i++) ps[i].lvl = prob[i];
}

inline void set_qst_level() {
    for (int i = 0; i < QC; i++) prob[i] = get_rand();
    sort(prob, prob + QC);
    for (int i = 0; i < QC; i++) qs[i].lvl = prob[i];
}


// inline double sigmoid(double x) { return 1 / (1 + exp(-x)); }
inline double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }

inline int judge() {
    int maxid = 0;
    double maxd = 0;
    for (int k = 0; k < PC; k++) {
        int id = 9999;
        ps[k].w = 0;
        for (int i = 99; i >= 95; i--) {//计算最难的500个题目,5 *100
            double real = 0, hope = 0;

            for (int j = 0; j < 100; j++) {
                real += (str[ps[k].idx][qs[id].idx] == '1');  //实际结果
                hope += sigmoid(ps[k].lvl - qs[id--].lvl);    //期望结果
            }
            ps[k].w += (real - hope) * pow(i, 2);//pow 当做是题目块的权值，100个题目为一块
        }
        if (ps[k].w > maxd) {  //计算期望结果和实际结果
            maxd = ps[k].w;
            maxid = ps[k].idx;
        }
    }
    return maxid + 1;
}
