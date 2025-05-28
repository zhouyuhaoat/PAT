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

struct Run {
    int val, run;
    Run(int val, int run) : val(val), run(run) {
    }
    friend bool operator<(Run a, Run b) {
        if (a.run != b.run) {
            return a.run > b.run;
        } else {
            return a.val > b.val;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    vector<vector<int>> runs(n);
    priority_queue<Run> q;
    for (int i = 0; i < m; i++) { // initialization
        q.emplace(data[i], 0);
    }
    for (int i = m; i < n; i++) {
        auto [val, run] = q.top(); // just output from internal memory, then write back to tape
        q.pop();
        runs[run].emplace_back(val);
        if (data[i] >= val) { // the current run: not smaller
            q.emplace(data[i], run);
        } else { // next new run
            q.emplace(data[i], run + 1);
        }
    }
    while (!q.empty()) { // the last run
        auto [val, run] = q.top();
        q.pop();
        runs[run].emplace_back(val);
    }
    for (int i = 0; i < n; i++) {
        if (runs[i].empty()) {
            break;
        }
        for (int j = 0; j < (int)runs[i].size(); j++) {
            cout << runs[i][j];
            j < (int)runs[i].size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
