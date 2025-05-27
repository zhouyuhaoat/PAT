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

bool isQueen(vector<int>& chess) {
    bitset<1001> row, diagMain, diagAnti; // of current column
    for (int x = 1; x < (int)chess.size(); x++) {
        int y = chess[x];
        if (row.test(y) || diagMain.test(y) || diagAnti.test(y)) {
            return false;
        }
        row.set(y), diagMain.set(y), diagAnti.set(y);
        diagMain >>= 1, diagAnti <<= 1;
        /*
            shift for next column
            1. main diagonal, from top left (down, >>) to bottom right
            2. anti diagonal, from bottom left (up, <<) to top right
        */
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> chess(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> chess[i];
        }
        isQueen(chess) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
