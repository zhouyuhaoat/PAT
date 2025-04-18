/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 09:43:15
 *	modified:	2023-04-03 10:07:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805348915855360 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1128 N Queens Puzzle
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805348915855360
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isQueen(vector<int> c) {
    unordered_map<int, bool> row, diagL, diagR;
    for (int i = 1; i < (int)c.size(); i++) {
        if (row[c[i]] || diagL[c[i] + i] || diagR[c[i] - i]) {
            return false;
        }
        row[c[i]] = true, diagL[c[i] + i] = true, diagR[c[i] - i] = true;
        // diagL: main diagonal, (row + column) is constant
        // diagR: anti diagonal, (row - column) is constant
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> c(n + 1); // all 1-based index
        // chessboard: left-bottom corner is (1, 1)
        for (int i = 1; i <= n; i++) { // column
            cin >> c[i]; // row
        }
        isQueen(c) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
