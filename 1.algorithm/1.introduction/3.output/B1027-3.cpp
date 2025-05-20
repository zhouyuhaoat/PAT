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
    /*
        calculate by two triangles => one parallelogram
        1. upper + middle = inverted triangle; down + 1(borrow) = triangle
        2. parallelogram = [2 * row - 1 + 1, row]
        3. all = 2 * row * row - 1(return)
    */
    int row = (int)sqrt((n + 1) / 2);
    for (int i = 1; i <= 2 * row - 1; i++) { // 1-based index
        int space, star;
        if (i <= row) { // upper + middle
            space = i - 1, star = 2 * (row - i) + 1;
        } else { // down
            space = 2 * row - 1 - i, star = 2 * (i - row) + 1;
        }
        /*
            gradient or coefficient of change
                1. upper + middle: space = +1, star = -2
                2. middle + down: space = -1, star = +2
            space by left-upper position (i = 1, space = 0) and left-down position (i = 2 * row - 1, space = 0)
            star by middle position (i = row, star = 1)
        */
        cout << string(space, ' ') << string(star, ch) << "\n";
    }
    cout << n - (2 * row * row - 1) << "\n";

    return 0;
}
// @pintia code=end
