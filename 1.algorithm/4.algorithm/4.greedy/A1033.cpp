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
    double pri = 0, dis = 0, tank = 0, ld = cmax * davg;
    int nextid = 0;
    while (nextid < n) {
        int nowid = nextid;
        if (nowid < n && s[nowid].d + ld < s[nowid + 1].d) { // not reachable to next station
            dis += ld;
            cout << "The maximum travel distance = " << fixed << setprecision(2) << dis << "\n";
            return 0;
        }
        for (int i = nowid + 1; i < n + 1; i++) {
            if (s[i].d - s[nowid].d <= ld) { // reachable
                if (s[i].p < s[nowid].p) { // cheaper
                    nextid = i;
                    break;
                    // greedy: no need to find the cheapest, just find the cheaper one
                }
            } else {
                break;
            }
        }
        if (nowid != nextid) { // cheaper
            double dif = s[nextid].d - s[nowid].d;
            dis += dif;
            double needtank = dif / davg;
            if (needtank > tank) { // need to fill
                pri += s[nowid].p * (needtank - tank);
                tank = 0; // just fill up
            } else { // enough
                tank -= needtank;
            }
        } else { // no cheaper
            double lp = INT_MAX;
            for (int i = nowid + 1; i < n + 1; i++) {
                if (s[i].d - s[nowid].d <= ld) {
                    // greedy: if no cheaper one, then find the cheapest one
                    if (s[i].p < lp) {
                        lp = s[i].p;
                        nextid = i;
                    }
                } else {
                    break;
                }
            }
            double dif = s[nextid].d - s[nowid].d;
            dis += dif;
            // greedy: current station is the cheapest one, so fill up
            pri += s[nowid].p * (cmax - tank);
            tank = cmax - dif / davg;
        }
    }
    cout << fixed << setprecision(2) << pri << "\n";

    return 0;
}
// @pintia code=end