/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 13:45:49
 *	modified:	2023-04-12 01:05:09
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805430595731456 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1049 Counting Ones
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805430595731456
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int cnt = 0, base = 1;
    while (n / base != 0) {
        /*
            divide a number into two parts by a line
            - left part: n / base; right part: n % base
            - if base = 10^i, then right part is i digits
        */
        int left = n / base / 10, cur = n / base % 10;
        int right = n % base;
        if (cur == 0) { // left_0_right => 0~left-1_1_0~base-1
            cnt += left * base;
        } else if (cur == 1) { // left_1_right => left_0_right + left_1_0~right
            cnt += left * base + right + 1;
        } else { // left_2~9_right => 0~left_1_0~base-1
            cnt += (left + 1) * base;
        }
        base *= 10;
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
