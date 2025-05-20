/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:08:18
 *	modified:	2023-03-22 11:11:50
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805325918486528 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1001 害死人不偿命的(3n+1)猜想
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805325918486528
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    // 3x + 1 problem, Collatz Conjecture, hailstone sequence
    int n;
    cin >> n;
    int step = 0;
    while (n != 1) {
        if (n % 2 != 0) {
            n = 3 * n + 1;
        }
        n /= 2;
        step++;
    }
    cout << step << "\n";

    return 0;
}
// @pintia code=end
