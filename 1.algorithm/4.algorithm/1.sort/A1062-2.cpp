/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 21:16:00
 *	modified:	2024-04-27 21:20:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805410555346944 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1062 Talent and Virtue
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805410555346944
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct per {
    int id;
    int vir, tal, tot;
};

int main(int argc, char const *argv[]) {

    int n, l, h;
    cin >> n >> l >> h;
    vector<per> p[4];
    int cnt = n;
    for (int i = 0; i < n; i++) {
        per t;
        cin >> t.id >> t.vir >> t.tal;
        t.tot = t.vir + t.tal;
        if (t.vir < l || t.tal < l) {
            cnt--;
            continue;
        } else if (t.vir >= h && t.tal >= h) {
            p[0].emplace_back(t);
        } else if (t.vir >= h && t.tal < h) {
            p[1].emplace_back(t);
        } else if (t.vir < h && t.tal < h && t.vir >= t.tal) {
            p[2].emplace_back(t);
        } else {
            p[3].emplace_back(t);
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < 4; i++) {
        sort(p[i].begin(), p[i].end(), [](per a, per b) -> bool {
            if (a.tot != b.tot) {
                return a.tot > b.tot;
            } else if (a.vir != b.vir) {
                return a.vir > b.vir;
            } else {
                return a.id < b.id;
            }
        });
        for (auto it : p[i]) {
            cout << it.id << " " << it.vir << " " << it.tal << "\n";
        }
    }

    return 0;
}
// @pintia code=end