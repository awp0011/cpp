#include <ctime>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <random>

struct info1 {
    int idx, rcnt;
    double level;
} qst[10000];

struct info2 {
    int idx, rcnt;
    double level;
    double hard_rare_real[10];
    double hard_rare_hope[10];
} peo[100];

using namespace std;
// float ;
double prob[10000];
bool ori_ret[100][10000];

inline bool cmp1(info1 x, info1 y);

inline bool cmp2(info2 x, info2 y);

inline void get_rand(int size);

inline void set_peo_level();

inline void set_qst_level();

inline double sigmoid(double x);

inline int judge();

random_device rd;  //Will be used to obtain a seed for the random number engine
mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
uniform_real_distribution<> dis(-3.0, 3.0);

int main() {

    freopen("C:\\Users\\peng0\\Downloads\\cheating_detection_sample_ts1_input.txt", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T, P, ans;
    string ret;
    cin >> T >> P;
    for (int tc = 1; tc <= T; tc++) {
        //初始化 问题
        for (int j = 0; j < 10000; j++) qst[j] = {j + 1, 0, 0};
        // read case
        for (int i = 0; i < 100; i++) {
            cin >> ret;
            peo[i] = {i + 1, 0, 0, {0}};
            for (int j = 0; j < 10000; j++) {
                ori_ret[i][j] = false;
                if (ret[j] == '1') {
                    peo[i].rcnt++;
                    qst[j].rcnt++;
                    ori_ret[i][j] = true;
                }
            }
        }
        //排序
        sort(peo, peo + 100, cmp2);
        sort(qst, qst + 10000, cmp1);
        //指定人的skill level
        set_peo_level();
        //指定题目difficult level
        set_qst_level();

        ans = judge();
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}

// 0~1之间的随机数


inline bool cmp1(info1 x, info1 y) { return x.rcnt > y.rcnt; }

inline bool cmp2(info2 x, info2 y) { return x.rcnt < y.rcnt; }

inline void set_peo_level() {
    for (int i = 0; i < 100; i++) prob[i] = dis(gen);
    sort(prob, prob + 100);
    for (int i = 0; i < 100; i++) peo[i].level = prob[i];
}

inline void set_qst_level() {
    for (int i = 0; i < 10000; i++) prob[i] = dis(gen);
    sort(prob, prob + 10000);
    for (int i = 0; i < 10000; i++) qst[i].level = prob[i];
}

inline double sigmoid(double x) { return 1 / (1 + exp(-x)); }

inline int judge() {
    int maxid = 0;
    double maxd = 0, error;
    //计算最难的1000个题目,10 *100
    for (int p = 0; p < 100; p++) {
        int id = 9999;
        error = 0;
        for (int i = 0; i < 10; i++) {
            peo[p].hard_rare_real[i] = 0;
            peo[p].hard_rare_hope[i] = 0;
            for (int j = 0; j < 100; j++) {
                //实际结果
                if (ori_ret[peo[p].idx - 1][qst[id].idx - 1])
                    peo[p].hard_rare_real[i]++;
                //期望结果
                peo[p].hard_rare_hope[i] += sigmoid(peo[p].level - qst[id--].level);
            }
            peo[p].hard_rare_real[i] /= 100;
            //最难得700题目，成功率达到50%，则输出结果
//            if (i < 7 && peo[p].hard_rare_real[i] >= 0.5) return peo[p].idx;

            peo[p].hard_rare_hope[i] /= 100;
            error += abs(peo[p].hard_rare_real[i] - peo[p].hard_rare_hope[i]);
            if (error > maxd) {  //计算期望结果和实际结果
                maxd = error;
                maxid = peo[p].idx;
            }
        }
    }
    return maxid;
}
