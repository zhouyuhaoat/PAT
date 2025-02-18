/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:30:21
 *	modified:	2023-03-22 21:38:06
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805284923359232 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1037 在霍格沃茨找零钱
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805284923359232
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int a, b, c;
    int unused __attribute__((unused));
    unused = scanf("%d.%d.%d", &a, &b, &c);
    int pt = a * 17 * 29 + b * 29 + c;
    unused = scanf("%d.%d.%d", &a, &b, &c);
    int at = a * 17 * 29 + b * 29 + c;
    int dif = at - pt;
    if (pt > at) {
        cout << "-";
        dif = -dif;
    }
    cout << dif / 29 / 17 << "." << dif / 29 % 17 << "." << dif % 29 << "\n";

    return 0;
}
// @pintia code=end