/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 23:42:25
 *	modified:	2023-04-13 08:50:22
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805498207911936 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1014 Waiting in Line
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805498207911936
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct cus { // customer
    int cid, wid, et; // customer id, window id, end time
    cus(int cid, int wid, int et) : cid(cid), wid(wid), et(et) {
    }
    friend bool operator<(cus a, cus b) { // min heap
        if (a.et != b.et) {
            return a.et > b.et;
        } else {
            return a.wid > b.wid;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, m, k, q;
    cin >> n >> m >> k >> q; // windows, capacity, customers, queries
    vector<int> d(k + 1); // processing time
    for (int i = 0; i < k; i++) {
        cin >> d[i + 1];
    }
    vector<queue<cus>> w(n + 1); // windows
    priority_queue<cus> c; // customers to be served
    vector<int> et(k + 1), wet(n + 1); // end time, end time of each window
    for (int i = 1; i <= m; i++) { // first m customers
        for (int j = 1; j <= n; j++) { // of each window
            int id = (i - 1) * n + j;
            if (id <= k) {
                wet[j] += d[id];
                et[id] = wet[j];
                w[j].emplace(id, j, wet[j]);
                if (i == 1) { // serving the first customer of each window
                    c.emplace(id, j, wet[j]);
                }
            } else {
                break;
            }
        }
    }
    for (int i = m * n + 1; i <= k; i++) { // remaining customers
        cus t = c.top(); // served
        c.pop();
        w[t.wid].pop(); // leave the window
        wet[t.wid] += d[i];
        et[i] = wet[t.wid];
        w[t.wid].emplace(i, t.wid, wet[t.wid]); // enter the window
        c.emplace(w[t.wid].front()); // serving the first customer of each window
    }
    for (int qq = 0; qq < q; qq++) {
        int id;
        cin >> id;
        if (et[id] - d[id] >= 540) {
            cout << "Sorry\n";
        } else {
            cout << setfill('0') << setw(2) << 8 + et[id] / 60 << ":" << setfill('0') << setw(2) << et[id] % 60 << "\n";
        }
    }

    return 0;
}
// @pintia code=end