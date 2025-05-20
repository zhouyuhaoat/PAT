/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:29:56
 *	modified:	2023-03-22 11:40:26
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805285812551680 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1036 跟奥巴马一起编程
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805285812551680
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    char ch;
    cin >> n >> ch;
    int col = n, row = n / 2.0 + 0.5;
    cout << string(col, ch) << "\n";
    for (int i = 1; i < row - 1; i++) {
        cout << ch << string(col - 2, ' ') << ch << "\n";
    }
    cout << string(col, ch) << "\n";

    return 0;
}
// @pintia code=end
