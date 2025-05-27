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
#include <iostream>
#include <vector>

using namespace std;

bool isQueen(vector<int>& chess) {
    for (int x2 = 1; x2 < (int)chess.size(); x2++) {
        for (int x1 = 1; x1 < x2; x1++) { // all previous columns
            int y1 = chess[x1], y2 = chess[x2];
            if (y1 == y2 || x2 - x1 == abs(y2 - y1)) {
                /*
                    gradient
                    - y1 = chess[x1], y2 = chess[x2]
                    - y1 = y2: same row
                    - x2 - x1 == abs(y2 - y1): same diagonal
                        1. x2 - x1: delta column
                        2. y2 - y1: delta row
                        3. gradient of diagonal = delta row / delta column = 1 or -1
                */
                return false;
            }
        }
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
