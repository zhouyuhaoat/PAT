/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 22:49:55
 *	modified:	2023-03-26 12:53:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805451374313472 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1037 Magic Coupon
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805451374313472
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int nc;
    cin >> nc;
    vector<int> c(nc);
    for (int i = 0; i < nc; i++) {
        cin >> c[i];
    }
    int np;
    cin >> np;
    vector<int> p(np);
    for (int i = 0; i < np; i++) {
        cin >> p[i];
    }
    sort(c.begin(), c.end());
    sort(p.begin(), p.end());
    int sum = 0;
    for (int i = 0; i < nc && i < np; i++) {
        if (c[i] < 0 && p[i] < 0) {
            sum += c[i] * p[i];
        }
        if (c[nc - i - 1] > 0 && p[np - i - 1] > 0) {
            sum += c[nc - i - 1] * p[np - i - 1];
        }
    }
    cout << sum << "\n";

    return 0;
}
// @pintia code=end