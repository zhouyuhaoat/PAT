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

struct station {
    double price, dist;
};

int main(int argc, char const *argv[]) {

    double cap, dist, per;
    int n;
    cin >> cap >> dist >> per >> n;
    vector<station> sta(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> sta[i].price >> sta[i].dist;
    }
    sta[n].price = 0, sta[n].dist = dist;
    sort(sta.begin(), sta.end(), [](station a, station b) {
        return a.dist < b.dist;
    });
    if (sta[0].dist != 0) {
        cout << "The maximum travel distance = 0.00\n";
        return 0;
    }
    double price = 0, tank = 0, range = cap * per;
    int now = 0;
    while (now < n) {
        int next = -1;
        double minPrice = INT_MAX;
        for (int i = now + 1; i <= n && sta[i].dist - sta[now].dist <= range; i++) { // reachable
            if (sta[i].price < minPrice) {
                minPrice = sta[i].price;
                next = i;
                if (minPrice < sta[now].price) { // lower price than current station
                    break;
                }
            }
        }
        if (next == -1) break; // not reachable
        double need = (sta[next].dist - sta[now].dist) / per;
        if (minPrice < sta[now].price) { // fill until the next station
            if (tank < need) {
                price += (need - tank) * sta[now].price;
                tank = 0;
            } else {
                tank -= need;
            }
        } else { // fill up at the current station
            price += (cap - tank) * sta[now].price;
            tank = cap - need;
        }
        now = next;
    }
    if (now == n) {
        cout << fixed << setprecision(2) << price << "\n";
    } else {
        cout << "The maximum travel distance = " << fixed << setprecision(2) << sta[now].dist + range << "\n";
    }

    return 0;
}
// @pintia code=end
