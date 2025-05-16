/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 15:53:43
 *	modified:	2023-03-23 16:09:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805526272000000 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1002 A+B for Polynomials
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805526272000000
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    map<int, double, greater<int>> poly; // polynomial: exponent -> coefficient
    for (int p = 0; p < 2; p++) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int exp;
            double coef;
            cin >> exp >> coef;
            poly[exp] += coef;
            if (poly[exp] == 0) { // zero coefficient
                poly.erase(exp);
            }
        }
    }
    cout << poly.size();
    for (auto [exp, coef] : poly) {
        cout << " " << exp << " " << fixed << setprecision(1) << coef;
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
