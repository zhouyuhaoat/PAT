/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 18:58:44
 *	modified:	2023-03-23 19:25:11
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805276438282240 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1048 数字加密
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805276438282240
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) { // align to the right
        a.insert(0, b.size() - a.size(), '0');
    } else {
        b.insert(0, a.size() - b.size(), '0');
    }
    int n = b.size();
    string encrypt = "0123456789JQK";
    for (int i = 0; i < n; i++) {
        int num1 = a[i] - '0', num2 = b[i] - '0';
        // size - i: the number of digits right, include the current digit
        if ((n - i) % 2 == 1) {
            b[i] = encrypt[(num1 + num2) % 13];
        } else {
            b[i] = encrypt[(num2 - num1 + 10) % 10];
        }
    }
    cout << b << "\n";

    return 0;
}
// @pintia code=end
