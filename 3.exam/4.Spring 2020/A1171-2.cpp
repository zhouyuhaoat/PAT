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
    vector<int> data(n);
    priority_queue<int, vector<int>, greater<int>> run1, run2; // the current run, next new run
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        if (i < m) {
            run1.emplace(data[i]);
        }
    }
    int idx = m;
    while (!run1.empty()) {
        int val = run1.top(); // just output from internal memory, then write back to tape
        run1.pop();
        cout << val;
        if (idx < n) {
            if (data[idx] >= val) { // the current run: not smaller
                run1.emplace(data[idx]);
            } else { // next new run
                run2.emplace(data[idx]);
            }
            idx++;
        }
        if (!run1.empty()) {
            cout << " ";
        } else {
            swap(run1, run2);
            cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
