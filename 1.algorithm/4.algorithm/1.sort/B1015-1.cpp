/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 13:05:34
 *	modified:	2023-03-23 13:26:51
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805307551629312 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1015 德才论
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805307551629312
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct per {
    int id;
    int vir, tal, tot;
    int flag;
};

int main(int argc, char const *argv[]) {

    int n, l, h;
    cin >> n >> l >> h;
    vector<per> p;
    for (int i = 0; i < n; i++) {
        per t;
        cin >> t.id >> t.vir >> t.tal;
        t.tot = t.vir + t.tal;
        if (t.vir < l || t.tal < l) {
            continue;
        } else if (t.vir >= h && t.tal >= h) {
            t.flag = 1;
        } else if (t.vir >= h && t.tal < h) {
            t.flag = 2;
        } else if (t.vir < h && t.tal < h && t.vir >= t.tal) {
            t.flag = 3;
        } else {
            t.flag = 4;
        }
        p.emplace_back(t);
    }
    sort(p.begin(), p.end(), [](per a, per b) -> bool {
        if (a.flag != b.flag) {
            return a.flag < b.flag;
        } else if (a.tot != b.tot) {
            return a.tot > b.tot;
        } else if (a.vir != b.vir) {
            return a.vir > b.vir;
        } else {
            return a.id < b.id;
        }
    });
    cout << p.size() << "\n";
    for (auto it : p) {
        cout << it.id << " " << it.vir << " " << it.tal << "\n";
    }

    return 0;
}
// @pintia code=end
