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
#include <map>
#include <vector>

using namespace std;

bool isque(vector<int> d) { // judge whether the queen is safe
    map<int, bool> row, diag1, diag2;
    for (int i = 1; i < (int)d.size(); i++) {
        if (row[d[i]] == false) {
            row[d[i]] = true;
        } else {
            return false;
        }
        if (diag1[d[i] + i] == false) { // main diagonal: (row + column) is constant
            diag1[d[i] + i] = true;
        } else {
            return false;
        }
        if (diag2[d[i] - i] == false) { // anti diagonal: (row - column) is constant
            diag2[d[i] - i] = true;
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> d(n + 1); // all 1-based index
        // chessboard: left-bottom corner is (1, 1)
        for (int j = 1; j <= n; j++) { // column
            cin >> d[j]; // row
        }
        if (isque(d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
// @pintia code=end