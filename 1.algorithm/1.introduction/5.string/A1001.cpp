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
    string c = to_string(a + b), res;
    for (int i = 0; i < (int)c.size(); i++) { // part or group by 3 digits
        res += c[i];
        if (i == 0 && c[i] == '-') { // sign
            continue;
        }
        // size - 1 - i: the number of digits right, exclude the current digit
        if ((c.size() - 1 - i) % 3 == 0) { // new part or group
            if (i < (int)c.size() - 1) { // not the last digit, part or group
                res += ",";
            }
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
