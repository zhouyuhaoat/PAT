/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 19:46:29
 *	modified:	2023-03-23 19:57:34
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805528788582400 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1001 A+B Format
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805528788582400
*/

// @pintia code=start
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int a, b;
    cin >> a >> b;
    string c = to_string(a + b);
    reverse(c.begin(), c.end());
    string d;
    for (int i = 0; i < (int)c.size(); i++) {
        if (i % 3 == 0 && i != 0 && c[i] != '-') {
            d = ',' + d;
        }
        d = c[i] + d;
    }
    cout << d << "\n";

    return 0;
}
// @pintia code=end
