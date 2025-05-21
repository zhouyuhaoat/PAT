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

struct Station {
    double price, dist;
};

int main(int argc, char const *argv[]) {

    double cap, dist, per; // capacity, distance, distance per unit
    int n;
    cin >> cap >> dist >> per >> n;
    vector<Station> sta(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> sta[i].price >> sta[i].dist;
    }
    sta[n].price = 0, sta[n].dist = dist; // destination
    sort(sta.begin(), sta.end(), [](Station a, Station b) {
        return a.dist < b.dist;
    });
    if (sta[0].dist != 0) { // source
        cout << "The maximum travel distance = 0.00\n";
        return 0;
    }
    int now = 0;
    double price = 0, tank = 0, range = cap * per;
    while (now < n) {
        if (now < n && sta[now].dist + range < sta[now + 1].dist) { // unreachable to next station
            cout << "The maximum travel distance = " << fixed << setprecision(2) << sta[now].dist + range << "\n";
            return 0;
        }
        int next = now;
        for (int i = now + 1; i <= n; i++) {
            if (sta[i].dist - sta[now].dist <= range) { // reachable
                // greedy: no need to find the cheapest, just find the cheaper one
                if (sta[i].price < sta[now].price) {
                    next = i;
                    break;
                }
            } else {
                break;
            }
        }
        if (next != now) { // cheaper
            double need = (sta[next].dist - sta[now].dist) / per;
            if (tank < need) { // need to fill
                price += (need - tank) * sta[now].price;
                tank = 0; // just fill up
            } else { // enough
                tank -= need;
            }
        } else { // not cheaper
            double minPrice = INT_MAX;
            for (int i = now + 1; i <= n; i++) {
                if (sta[i].dist - sta[now].dist <= range) {
                    // greedy: if no cheaper one, then find the cheapest one, even more expensive than current
                    if (sta[i].price < minPrice) {
                        minPrice = sta[i].price;
                        next = i;
                    }
                } else {
                    break;
                }
            }
            // greedy: current station is the cheapest one, so fill up
            price += (cap - tank) * sta[now].price;
            tank = cap - (sta[next].dist - sta[now].dist) / per;
        }
        now = next;
    }
    cout << fixed << setprecision(2) << price << "\n";

    return 0;
}
// @pintia code=end
