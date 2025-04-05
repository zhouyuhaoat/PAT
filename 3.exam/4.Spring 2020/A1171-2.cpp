/*
 *	author:		zhouyuhao
 *	created:	2024-05-16 23:17:36
 *	modified:	2024-05-16 23:24:27
 *	item:		Programming Ability Test
 *	site:		226, Harbin
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

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    priority_queue<int, vector<int>, greater<int>> q1, q2; // the current run, next new run
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (i < m) {
            q1.emplace(d[i]);
        }
    }
    int idx = m; // index
    while (!q1.empty()) {
        int t = q1.top(); // just output
        q1.pop();
        cout << t;
        if (idx < n) { // t = last in
            if (d[idx] >= t) { // the current run: not smaller than just output
                q1.emplace(d[idx]);
            } else { // next new run
                q2.emplace(d[idx]);
            }
            idx++;
        }
        if (!q1.empty()) {
            cout << " ";
        } else {
            swap(q1, q2); // swap the two runs
            cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end