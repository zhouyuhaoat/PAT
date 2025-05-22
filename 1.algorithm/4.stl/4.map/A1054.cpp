/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 22:24:59
 *	modified:	2023-03-26 22:29:43
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805422639136768 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1054 The Dominant Color
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805422639136768
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    unordered_map<int, int> cnt; // color -> count
    int threshold = m * n / 2; // dominant: more than half of the total pixels
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int color;
            cin >> color;
            if (++cnt[color] > threshold) {
                cout << color << "\n";
                return 0;
            }
        }
    }

    return 0;
}
// @pintia code=end
