/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:42:45
 *	modified:	2023-03-31 16:20:52
 *	item:		Programming Ability Test
 *	site:		Yuting
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

bool valid(Person a) {
    if (a.year > 1814 && a.year < 2014) {
        return true;
    } else if (a.year == 1814) {
        if (a.month > 9 || (a.month == 9 && a.day >= 6)) {
            return true;
        }
    } else if (a.year == 2014) {
        if (a.month < 9 || (a.month == 9 && a.day <= 6)) {
            return true;
        }
    }
    return false;
}

bool younger(Person a, Person b) {
    if (a.year != b.year) {
        return a.year > b.year;
    } else if (a.month != b.month) {
        return a.month > b.month;
    } else {
        return a.day > b.day;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int cnt = 0;
    Person old = {"", 2014, 9, 7}, young = {"", 1814, 9, 5}; // oldest, youngest
    for (int i = 0; i < n; i++) {
        Person p;
        cin >> p.name;
        scanf("%d/%d/%d", &p.year, &p.month, &p.day);
        if (valid(p)) {
            cnt++;
            if (younger(p, young)) {
                young = p;
            }
            if (!younger(p, old)) { // !younger => older
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
