/*
 *	author:		zhouyuhao
 *	created:	2025-04-14 14:01:26
 *	modified:	2025-04-14 14:57:20
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805458722734080 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1033 To Fill or Not to Fill
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805458722734080
*/

// @pintia code=start
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct sta {
    double p, d;
};

int main(int argc, char const *argv[]) {

    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    vector<sta> s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> s[i].p >> s[i].d;
    }
    s[n].p = 0, s[n].d = d;
    sort(s.begin(), s.end(), [](sta a, sta b) {
        return a.d < b.d;
    });
    if (s[0].d != 0) {
        cout << "The maximum travel distance = 0.00\n";
        return 0;
    }
    double pri = 0, tank = 0, range = cmax * davg;
    int now = 0;
    while (now < n) {
        int next = -1;
        double minpri = INT_MAX; // min price
        for (int i = now + 1; i <= n && s[i].d - s[now].d <= range; i++) { // reachable
            if (minpri > s[i].p) {
                minpri = s[i].p;
                next = i;
                if (minpri < s[now].p) { // lower price
                    break;
                }
            }
        }
        if (next == -1) break; // not reachable
        double need = (s[next].d - s[now].d) / davg;
        if (minpri < s[now].p) { // fill until the next station
            if (tank < need) {
                pri += (need - tank) * s[now].p;
                tank = 0;
            } else {
                tank -= need;
            }
        } else { // fill up at the current station
            pri += (cmax - tank) * s[now].p;
            tank = cmax - need;
        }
        now = next;
    }
    if (now == n) {
        cout << fixed << setprecision(2) << pri << "\n";
    } else {
        cout << "The maximum travel distance = " << fixed << setprecision(2) << s[now].d + range << "\n";
    }

    return 0;
}
// @pintia code=end
