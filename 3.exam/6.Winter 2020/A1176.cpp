/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 15:13:36
 *	modified:	2023-04-14 15:22:57
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1729419732192542720 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1176 The Closest Fibonacci Number
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542720
*/

// @pintia code=start
#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int res = 0, minAbs = INT_MAX;
    /*
        Fibonacci sequence
        - f(n) = f(n-1) + f(n-2)
        - f(-1) = 1, f(0) = 0 => f(1) = 1
    */
    int f = 1, g = 0;
    while (g < 2 * n) {
        g += f;
        f = g - f;
        if (abs(g - n) < minAbs) {
            minAbs = abs(g - n);
            res = g;
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
