/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 09:51:59
 *	modified:	2023-04-11 10:02:04
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805260223102976 pid=994805275792359424 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1049 数列的片段和
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805275792359424
*/

// @pintia code=start
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    /*
        each element contributes to the sum of all segments that include it
        - assume from left to right since order does not matter
            - value:             0.1    0.2    0.3    0.4
            - count of each:
            - from 0.1 to others: 4      3      2      1
            - from 0.2 to others:        3      2      1
            - from 0.3 to others:               2      1
            - form 0.4 to others:                      1
        - row: n - i; col: i + 1
    */
    long double sum = 0;
    for (int i = 0; i < n; i++) {
        long double v;
        cin >> v;
        sum += v * (i + 1) * (n - i);
    }
    cout << fixed << setprecision(2) << sum << "\n";

    return 0;
}
// @pintia code=end
