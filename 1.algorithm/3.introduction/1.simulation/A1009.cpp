/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 16:12:36
 *	modified:	2023-03-23 16:21:17
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805509540921344 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1009 Product of Polynomials
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805509540921344
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    map<int, double, greater<int>> poly1, poly2; // polynomial: exponent -> coefficient
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int exp;
        double coef;
        cin >> exp >> coef;
        poly1[exp] = coef;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int exp2;
        double coef2;
        cin >> exp2 >> coef2;
        for (auto [exp1, coef1] : poly1) { // product
            poly2[exp1 + exp2] += coef1 * coef2;
            if (poly2[exp1 + exp2] == 0) {
                poly2.erase(exp1 + exp2);
            }
        }
    }
    cout << poly2.size();
    for (auto [exp, coef] : poly2) {
        cout << " " << exp << " " << fixed << setprecision(1) << coef;
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
