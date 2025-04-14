/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 13:43:19
 *	modified:	2023-03-22 13:55:31
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805301562163200 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1020 月饼
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805301562163200
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct mc {
    double st, ts;
    double s;
};

int main(int argc, char const *argv[]) {

    int n;
    double d;
    cin >> n >> d;
    vector<mc> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].st;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i].ts;
        c[i].s = c[i].ts / c[i].st;
    }
    sort(c.begin(), c.end(), [](mc a, mc b) {
        return a.s > b.s;
    });
    double tr = 0;
    for (int i = 0; i < n; i++) {
        if (d > c[i].st) {
            tr += c[i].ts;
            d -= c[i].st;
        } else {
            tr += d * c[i].s;
            break;
        }
    }
    cout << fixed << setprecision(2) << tr << "\n";

    return 0;
}
// @pintia code=end
