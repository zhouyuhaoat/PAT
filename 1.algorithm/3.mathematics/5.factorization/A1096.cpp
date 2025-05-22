/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:19:04
 *	modified:	2023-04-11 20:00:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805370650738688 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1096 Consecutive Factors
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805370650738688
*/

// @pintia code=start
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int first = 1, len = 0, sqr = sqrt(n) + 1;
    // prime factor: i * i <= n; i <= sqrt(n) => consecutive factor: i <= sqrt(n) + 1
    // e.g.: n = 30, sqrt(30) = 5.47 = 5, but 30 = 5 * 6
    for (int lo = 2; lo <= sqr; lo++) {
        int hi = lo, product = 1;
        for (; hi <= sqr; hi++) {
            product *= hi;
            if (n % product != 0) {
                break;
            }
        }
        if (len < hi - lo) {
            len = hi - lo;
            first = lo;
        }
    }
    if (len == 0) {
        cout << "1\n" << n << "\n";
    } else {
        cout << len << "\n";
        for (int i = 0; i < len; i++) {
            cout << first + i;
            i < len - 1 ? cout << "*" : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
