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

struct peo {
    string name;
    int y, m, d;
};

bool valid(peo a) {
    if (a.y > 1814 && a.y < 2014) {
        return true;
    } else if (a.y == 1814) {
        if (a.m > 9 || (a.m == 9 && a.d >= 6)) {
            return true;
        }
    } else if (a.y == 2014) {
        if (a.m < 9 || (a.m == 9 && a.d <= 6)) {
            return true;
        }
    }
    return false;
}

bool younger(peo a, peo b) {
    if (a.y != b.y) {
        return a.y > b.y;
    } else if (a.m != b.m) {
        return a.m > b.m;
    } else {
        return a.d > b.d;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    peo o = {"", 2014, 9, 7}, y = {"", 1814, 9, 5};
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        peo tmp;
        cin >> tmp.name;
        scanf("%d/%d/%d", &tmp.y, &tmp.m, &tmp.d);
        if (valid(tmp)) {
            cnt++;
            if (younger(tmp, y)) {
                y = tmp;
            }
            if (!younger(tmp, o)) { // !younger => older
                o = tmp;
            }
        }
    }
    if (cnt != 0) {
        cout << cnt << " " << o.name << " " << y.name << "\n";
    } else {
        cout << cnt << "\n";
    }

    return 0;
}
// @pintia code=end
