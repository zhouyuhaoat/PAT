/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 21:59:05
 *	modified:	2023-04-12 23:42:02
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805491530579968 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1017 Queueing at Bank
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805491530579968
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct cus { // customer
    int t, p; // arrival time, processing time
    cus(int t, int p) : t(t), p(p) {
    }
    friend bool operator<(cus a, cus b) {
        return a.t > b.t;
    }
};

int trans(int h, int m, int s) {
    return h * 60 * 60 + m * 60 + s;
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    priority_queue<cus> c; // customers
    int be = trans(8, 0, 0), en = trans(17, 0, 0); // begin, end
    for (int i = 0; i < n; i++) {
        int h, m, s, p;
        int unused __attribute__((unused)) = 0;
        unused = scanf("%d:%d:%d %d", &h, &m, &s, &p);
        if (p > 60) p = 60; // max processing time
        if (trans(h, m, s) > en) continue; // shutter
        c.emplace(trans(h, m, s), p * 60);
    }
    n = c.size();
    int wait = 0; // waiting time
    priority_queue<int, vector<int>, greater<int>> w; // end time of windows
    for (int i = 0; i < k; i++) {
        if (!c.empty()) {
            cus ct = c.top();
            c.pop();
            if (ct.t < be) { // before open
                wait += be - ct.t;
                ct.t = be;
            }
            w.emplace(ct.t + ct.p);
        } else {
            break;
        }
    }
    while (!c.empty()) {
        cus ct = c.top();
        c.pop();
        int wt = w.top(); // the earliest end time of windows
        w.pop();
        if (ct.t < wt) { // busy
            wait += wt - ct.t;
            w.emplace(wt + ct.p);
        } else { // idle
            w.emplace(ct.t + ct.p);
        }
    }
    cout << fixed << setprecision(1) << (double)wait / n / 60 << "\n";

    return 0;
}
// @pintia code=end