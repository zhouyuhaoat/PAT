/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 18:30:00
 *	modified:	2024-04-27 18:35:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
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

void print(int n, char ch) {
    for (int i = 0; i < n; i++) {
        cout << ch;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    char ch;
    cin >> n >> ch;
    // calculate by arithmetic sequence
    // up + middle: 1, 3, ..., 2 * row - 1
    // up + middle: (1 + 2 * row - 1) * row / 2 = row * row
    // down: row * row - 1
    // all: 2 * row * row - 1
    int row = (int)sqrt((n + 1) / 2); // floor
    int col = 2 * row - 1;
    for (int i = 0; i < row; i++) {
        print(i, ' '), print(col, ch), cout << "\n";
        col -= 2;
    }
    col += 2;
    for (int i = row - 2; i >= 0; i--) {
        col += 2;
        print(i, ' '), print(col, ch), cout << "\n";
    }
    cout << n - (2 * row * row - 1) << "\n";

    return 0;
}
// @pintia code=end
