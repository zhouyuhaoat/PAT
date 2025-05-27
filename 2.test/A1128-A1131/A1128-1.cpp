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

bool isQueen(vector<int>& chess) {
    /*
        left-bottom corner is origin, column is x-axis, row is y-axis
        main diagonal: y = -x + b => row + column = constant
        anti diagonal: y = x + b => row - column = constant
    */
    unordered_map<int, bool> row, diagMain, diagAnti;
    for (int x = 1; x < (int)chess.size(); x++) {
        int y = chess[x];
        if (row[y] || diagMain[y + x] || diagAnti[y - x]) {
            return false;
        }
        row[y] = true, diagMain[y + x] = true, diagAnti[y - x] = true;
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> chess(n + 1); // all 1-based index
        // chessboard: left-bottom corner is (1, 1)
        for (int i = 1; i <= n; i++) { // column
            cin >> chess[i]; // row
        }
        isQueen(chess) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
