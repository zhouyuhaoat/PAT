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
#include <map>
#include <vector>

using namespace std;

bool isque(vector<int> d) {
    for (int i = 1; i < (int)d.size(); i++) { // <, not <=
        for (int j = 1; j < i; j++) {
            if (d[i] == d[j] || abs(d[i] - d[j]) == abs(i - j)) {
                // d[i] == d[j]: same column
                // abs(d[i] - d[j]) == abs(i - j): same diagonal
                return false;
            }
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
        vector<int> d(n + 1);
        for (int j = 1; j <= n; j++) {
            cin >> d[j];
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