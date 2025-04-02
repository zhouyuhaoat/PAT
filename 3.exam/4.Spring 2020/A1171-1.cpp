/*
 *	author:		zhouyuhao
 *	created:	2023-04-06 11:12:00
 *	modified:	2023-04-06 11:33:03
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1621700097589465088 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1171 Replacement Selection
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1621700097589465088
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v, r; // value, run
    node(int v, int r) : v(v), r(r) { // constructor
    }
    friend bool operator<(node a, node b) { // overload < operator for min-heap
        if (a.r != b.r) {
            return a.r > b.r;
        } else {
            return a.v > b.v;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<vector<int>> run(n); // runs
    priority_queue<node> q;
    for (int i = 0; i < m; i++) { // initialization
        q.emplace(d[i], 0);
    }
    for (int i = m; i < n; i++) {
        node t = q.top();
        q.pop();
        run[t.r].emplace_back(t.v); // t.v = last in
        if (d[i] > t.v) { // the current run
            q.emplace(d[i], t.r);
        } else { // next new run
            q.emplace(d[i], t.r + 1);
        }
    }
    while (!q.empty()) { // the last run
        node t = q.top();
        q.pop();
        run[t.r].emplace_back(t.v);
    }
    for (int i = 0; i < n; i++) {
        if (run[i].empty()) {
            break;
        }
        for (int j = 0; j < (int)run[i].size(); j++) {
            cout << run[i][j];
            j < (int)run[i].size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end