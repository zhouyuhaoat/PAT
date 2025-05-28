/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 10:52:36
 *	modified:	2024-05-17 11:11:27
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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

const int NUM = 1e5 + 1;
vector<bool> sum(2 * NUM - 1), dup(NUM); // difference -> summation

int main(int argc, char const *argv[]) {

    int n1, n2;
    cin >> n1 >> n2;
    sum[n1] = sum[n2] = true; // assume there is one 0 initially
    dup[n1] = dup[n2] = true;
    vector<int> pre = {n1, n2};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i + 1][j + 1];
        }
    }
    vector<bool> out(n + 1);
    for (int q = 1; q <= m; q++) {
        for (int i = 1; i <= n; i++) {
            if (out[i]) continue;
            int num = d[i][q];
            bool diff = false;
            for (int it : pre) {
                if (sum[it + num]) { // it + num - num = it
                    diff = true;
                    break;
                }
            }
            if (diff && !dup[num]) {
                sum[num] = dup[num] = true;
                pre.emplace_back(num);
            } else {
                cout << "Round #" << q << ": " << i << " is out.\n";
                out[i] = true;
            }
        }
    }
    vector<int> win;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            win.emplace_back(i);
        }
    }
    if (!win.empty()) {
        cout << "Winner(s):";
        for (int id : win) {
            cout << " " << id;
        }
        cout << "\n";
    } else {
        cout << "No winner.\n";
    }

    return 0;
}
// @pintia code=end
