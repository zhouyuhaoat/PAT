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

struct Person {
    string name;
    int year, month, day;
};

bool younger(Person a, Person b, bool flag) {
    if (a.year != b.year) {
        return a.year > b.year;
    } else if (a.month != b.month) {
        return a.month > b.month;
    } else if (a.day != b.day) {
        return a.day > b.day;
    }
    return flag;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int cnt = 0;
    Person old = {"", 2014, 9, 7}, young = {"", 1814, 9, 5};
    Person lo = young, hi = old; // boundary
    for (int i = 0; i < n; i++) {
        Person p;
        cin >> p.name;
        scanf("%d/%d/%d", &p.year, &p.month, &p.day);
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
