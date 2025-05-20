/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 18:40:00
 *	modified:	2025-04-07 18:45:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805294251491328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1027 打印沙漏
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805294251491328
*/

// @pintia code=start
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    char ch;
    cin >> n >> ch;
    int row = (int)sqrt((n + 1) / 2);
    for (int i = 1; i <= 2 * row - 1; i++) {
        int dist = abs(row - i); // distance from the middle row
        int space = row - 1 - dist, star = 2 * dist + 1;
        /*
            row: 1 -> row -> 2 * row - 1
                - symmetry by middle position
                1. dist: row - 1 -> 0 -> row - 1
                2. space: 0 -> row - 1 -> 0
                3. star: 2 * row - 1 -> 1 -> 2 * row - 1
            space and star by middle position (i = row, dist = 0, space = row - 1, star = 1)
        */
        cout << string(space, ' ') << string(star, ch) << "\n";
    }
    cout << n - (2 * row * row - 1) << "\n";

    return 0;
}
// @pintia code=end
