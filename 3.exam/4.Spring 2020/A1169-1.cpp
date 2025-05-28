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

const int NUM = 1e5 + 1;
vector<bool> diff(NUM), dup(NUM); // difference, duplicate

int main(int argc, char const *argv[]) {

    int n1, n2;
    cin >> n1 >> n2;
    diff[abs(n1 - n2)] = true;
    dup[n1] = dup[n2] = true;
    vector<int> pre = {n1, n2}; // previous numbers
    int n, m;
    cin >> n >> m;
    vector<vector<int>> data(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> data[i + 1][j + 1];
        }
    }
    int cntOut = 0;
    vector<bool> out(n + 1); // kicked out
    for (int q = 1; q <= m && cntOut < n; q++) {
        vector<int> outID;
        for (int i = 1; i <= n; i++) {
            if (out[i]) continue;
            int num = data[i][q];
            /*
                1. must be the difference of two numbers that are previously given
                2. and must not be duplicated to any of the existed numbers
            */
            if (diff[num] && !dup[num]) { // next round
                for (int it : pre) { // update diff by all previous numbers
                    diff[abs(it - num)] = true;
                }
                dup[num] = true;
                pre.emplace_back(num);
            } else { // kicked out
                out[i] = true;
                outID.emplace_back(i);
                if (++cntOut == n) {
                    break;
                }
            }
        }
        for (int id : outID) {
            cout << "Round #" << q << ": " << id << " is out.\n";
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
