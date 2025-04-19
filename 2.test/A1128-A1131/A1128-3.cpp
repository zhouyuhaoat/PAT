/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 09:43:15
 *	modified:	2025-04-07 10:07:32
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805348915855360 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1128 N Queens Puzzle
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805348915855360
*/

// @pintia code=start
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

bool isQueen(vector<int> c) {
    bitset<1001> row, diagL, diagR; // of each column
    for (int i = 1; i < (int)c.size(); i++) {
        if (row.test(c[i]) || diagL.test(c[i]) || diagR.test(c[i])) {
            return false;
        }
        row.set(c[i]), diagL.set(c[i]), diagR.set(c[i]);
        diagL >>= 1, diagR <<= 1; // shift for next column
        // diagL: main diagonal, from top left (down, >>) to bottom right
        // diagR: anti diagonal, from bottom left (up, <<) to top right
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        isQueen(c) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
