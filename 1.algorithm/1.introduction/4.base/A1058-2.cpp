/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 15:55:00
 *	modified:	2024-04-27 15:59:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805416519647232 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1058 A+B in Hogwarts
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805416519647232
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int a1, a2, a3, b1, b2, b3;
    scanf("%d.%d.%d", &a1, &a2, &a3);
    scanf("%d.%d.%d", &b1, &b2, &b3);
    int s1, s2, s3;
    s3 = a3 + b3;
    s2 = a2 + b2 + s3 / 29, s3 %= 29; // carry
    s1 = a1 + b1 + s2 / 17, s2 %= 17;
    cout << s1 << "." << s2 << "." << s3 << "\n";

    return 0;
}
// @pintia code=end
