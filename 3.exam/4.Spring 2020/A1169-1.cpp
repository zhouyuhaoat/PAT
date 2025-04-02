/*
 *	author:		zhouyuhao
 *	created:	2023-04-06 08:50:22
 *	modified:	2023-04-06 11:05:43
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1621700048826490880 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1169 The Judger
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1621700048826490880
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 1;
vector<bool> dif(maxn), dup(maxn); // difference, duplicate

int main(int argc, char const *argv[]) {

    int n1, n2;
    cin >> n1 >> n2;
    dif[abs(n1 - n2)] = true;
    dup[n1] = dup[n2] = true;
    vector<int> pre = {n1, n2}; // previous numbers
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int>(m + 1)); // data
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i + 1][j + 1];
        }
    }
    vector<bool> out(n + 1); // kicked out
    int cntout = 0;
    for (int q = 1; q <= m && cntout < n; q++) {
        vector<int> outid;
        for (int i = 1; i <= n; i++) {
            if (out[i]) {
                continue;
            }
            int num = d[i][q];
            // 1. must be the difference of two numbers that are previously given
            // 2. and must not be duplicated to any of the existed numbers
            if (dif[num] && !dup[num]) { // next round
                for (auto it : pre) { // update dif by all previous numbers
                    dif[abs(it - num)] = true;
                }
                dup[num] = true;
                pre.emplace_back(num);
            } else { // kicked out
                out[i] = true;
                outid.emplace_back(i);
                if (++cntout == n) {
                    break;
                }
            }
        }
        for (auto it : outid) {
            cout << "Round #" << q << ": " << it << " is out.\n";
        }
    }
    vector<int> win; // winners
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            win.emplace_back(i);
        }
    }
    if (!win.empty()) {
        cout << "Winner(s):";
        for (auto it : win) {
            cout << " " << it;
        }
        cout << "\n";
    } else {
        cout << "No winner.\n";
    }

    return 0;
}
// @pintia code=end