/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 19:46:29
 *	modified:	2025-04-07 19:57:34
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805528788582400 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1001 A+B Format
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805528788582400
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int a, b;
    cin >> a >> b;
    string c = to_string(a + b), d;
    for (int i = 0; i < (int)c.size(); i++) {
        d += c[i];
        if (c[i] == '-') continue;
        if ((c.size() - i - 1) % 3 == 0) {
            // size - i - 1: the number of digits after the current digit
            if (i < (int)c.size() - 1) { // not the last digit, part or group
                d += ",";
            }
        }
    }
    cout << d << "\n";

    return 0;
}
// @pintia code=end
