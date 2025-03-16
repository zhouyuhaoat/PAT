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
    map<int, bool> row, diagonal;
    for (int i = 0; i < (int)d.size(); i++) {
        if (row[d[i]] == false) {
            row[d[i]] = true;
        } else {
            return false;
        }
        if (diagonal[d[i] + i] == false) { // diagonal line
            diagonal[d[i] + i] = true;
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
        vector<int> d(n);
        for (int j = 0; j < n; j++) {
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