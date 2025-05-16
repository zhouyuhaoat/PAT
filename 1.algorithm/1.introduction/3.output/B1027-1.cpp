/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:04:17
 *	modified:	2023-03-22 21:16:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805294251491328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1027 打印沙漏
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805294251491328
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    char ch;
    cin >> n >> ch;
    int cnt = n; // calculate manually
    cnt--; // the middle one
    int row = 1, col = 1;
    while (cnt >= 2 * (col + 2)) { // up and down
        col += 2;
        cnt -= 2 * col;
        row++;
    }
    for (int i = 0; i < row; i++) { // up + middle
        cout << string(i, ' ') << string(col, ch) << "\n";
        col -= 2;
    }
    col += 2; // restore the middle one
    for (int i = row - 2; i >= 0; i--) { // down
        col += 2;
        cout << string(i, ' ') << string(col, ch) << "\n";
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
