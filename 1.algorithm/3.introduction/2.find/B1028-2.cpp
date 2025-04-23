/*
 *	author:		zhouyuhao
 *	created:	2024-05-01 16:10:00
 *	modified:	2024-05-01 16:10:10
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805293282607104 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1028 人口普查
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805293282607104
*/

// @pintia code=start
#include <iostream>

using namespace std;

struct peo {
    string name;
    int y, m, d;
};

bool younger(peo a, peo b, bool flag) {
    if (a.y != b.y) {
        return a.y > b.y;
    } else if (a.m != b.m) {
        return a.m > b.m;
    } else if (a.d != b.d) {
        return a.d > b.d;
    }
    return flag;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    peo old = {"", 2014, 9, 7}, young = {"", 1814, 9, 5};
    peo lo = young, hi = old; // boundary
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        peo p;
        cin >> p.name;
        scanf("%d/%d/%d", &p.y, &p.m, &p.d);
        if (younger(p, lo, false) && !younger(p, hi, true)) {
            // valid: younger than the oldest and older than the youngest
            cnt++;
            if (younger(p, young, false)) {
                young = p;
            }
            if (!younger(p, old, true)) {
                old = p;
            }
        }
    }
    if (cnt != 0) {
        cout << cnt << " " << old.name << " " << young.name << "\n";
    } else {
        cout << cnt << "\n";
    }

    return 0;
}
// @pintia code=end
