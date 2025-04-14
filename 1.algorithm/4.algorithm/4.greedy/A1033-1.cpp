/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 14:01:26
 *	modified:	2023-03-31 23:06:10
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    s[n].p = 0, s[n].d = d; // terminal
    sort(s.begin(), s.end(), [](sta a, sta b) {
        return a.d < b.d;
    });
    if (s[0].d != 0) { // no start
        cout << "The maximum travel distance = 0.00\n";
        return 0;
    }
    double pri = 0, tank = 0, range = cmax * davg;
    int now = 0;
    while (now < n) {
        if (now < n && s[now].d + range < s[now + 1].d) { // not reachable to next station
            cout << "The maximum travel distance = " << fixed << setprecision(2) << s[now].d + range << "\n";
            return 0;
        }
        int next = now;
        for (int i = now + 1; i <= n; i++) {
            if (s[i].d - s[now].d <= range) { // reachable
                // greedy: no need to find the cheapest, just find the cheaper one
                if (s[i].p < s[now].p) {
                    next = i;
                    break;
                }
            } else {
                break;
            }
        }
        if (next != now) { // cheaper
            double need = (s[next].d - s[now].d) / davg;
            if (tank < need) { // need to fill
                pri += (need - tank) * s[now].p;
                tank = 0; // just fill up
            } else { // enough
                tank -= need;
            }
        } else { // not cheaper
            double minpri = INT_MAX; // min price
            for (int i = now + 1; i <= n; i++) {
                if (s[i].d - s[now].d <= range) {
                    // greedy: if no cheaper one, then find the cheapest one
                    if (minpri > s[i].p) {
                        minpri = s[i].p;
                        next = i;
                    }
                } else {
                    break;
                }
            }
            // greedy: current station is the cheapest one, so fill up
            pri += (cmax - tank) * s[now].p;
            tank = cmax - (s[next].d - s[now].d) / davg;
        }
        now = next;
    }
    cout << fixed << setprecision(2) << pri << "\n";

    return 0;
}
// @pintia code=end
