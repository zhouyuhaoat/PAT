/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 13:56:42
 *	modified:	2023-03-22 14:01:26
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805298269634560 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1023 组个最小数
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805298269634560
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n = 10, num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i < n; i++) {
        if (num[i]-- > 0) {
            cout << i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < num[i]; j++) {
            cout << i;
        }
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
