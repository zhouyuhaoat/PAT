/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:07:40
 *	modified:	2023-03-31 15:52:46
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805406352654336 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1065 A+B and C (64bit)
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805406352654336
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long sum = a + b;
        bool greater = false; // assume a + b <= c if 64-bit
        if (a > 0 && b > 0 && sum < 0) {
            greater = true;
        } else if (!(a < 0 && b < 0 && sum >= 0) && sum > c) {
            greater = true;
        }
        /*
            overflow
                - a > 0 && b > 0 && sum < 0
                - 2^63 - 1 + 2^63 - 1 = 2^64 - 2 = -2 (mod 2^64)
            underflow
                - a < 0 && b < 0 && sum >= 0
                - -2^63 + (-2^63) = -2^64 = 0 (mod 2^64)
        */
        cout << "Case #" << i + 1;
        greater ? cout << ": true\n" : cout << ": false\n";
    }

    return 0;
}
// @pintia code=end
