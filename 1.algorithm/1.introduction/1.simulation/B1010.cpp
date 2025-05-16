/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:19:55
 *	modified:	2023-03-23 15:50:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805313708867584 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1010 一元多项式求导
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805313708867584
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    map<int, int, greater<int>> poly; // polynomial: exponent -> coefficient
    int coef, exp;
    while (cin >> coef >> exp) {
        if (coef * exp != 0) { // non-zero coefficient
            poly.emplace(exp - 1, coef * exp); // derivative
        }
    }
    if (poly.empty()) {
        cout << "0 0\n";
    } else {
        for (auto it = poly.begin(); it != poly.end(); it++) {
            cout << it->second << " " << it->first;
            next(it) != poly.end() ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
