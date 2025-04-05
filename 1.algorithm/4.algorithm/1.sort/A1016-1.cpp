/*
 *	author:		zhouyuhao
 *	created:	2024-04-26 16:27:30
 *	modified:	2024-04-26 17:00:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805493648703488 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1016 Phone Bills
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805493648703488
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct per {
    string name;
    int M, d, h, m, t;
    string line;
};

int toll[25];
double calfare(per a, per b) {
    // calculate fare between two records
    double fare = (b.d - a.d) * toll[24] * 60;
    int flag = 1;
    if (a.h * 60 + a.m > b.h * 60 + b.m) {
        swap(a, b);
        flag = -1;
    }
    for (int i = a.h + 1; i < b.h; i++) {
        fare += flag * toll[i] * 60;
    }
    if (a.h == b.h) {
        fare += flag * (b.m - a.m) * toll[a.h];
    } else { // cross the hour
        fare += flag * (60 - a.m) * toll[a.h];
        fare += flag * b.m * toll[b.h];
    }
    return fare;
}

int main(int argc, char const *argv[]) {

    for (int i = 0; i < 24; i++) {
        cin >> toll[i];
        toll[24] += toll[i];
    }
    int n;
    cin >> n;
    vector<per> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].name;
        int unused __attribute__((unused)) = 0;
        unused = scanf("%d:%d:%d:%d", &p[i].M, &p[i].d, &p[i].h, &p[i].m);
        p[i].t = p[i].d * 24 * 60 + p[i].h * 60 + p[i].m;
        cin >> p[i].line;
    }
    sort(p.begin(), p.end(), [](per a, per b) -> bool {
        if (a.name != b.name) {
            return a.name < b.name;
        } else {
            return a.t < b.t;
        }
    });
    vector<per> b;
    for (int i = 0; i < n - 1; i++) { // n - 1: avoid out of range
        if (p[i].name == p[i + 1].name) { // pair after sort: on-line & off-line
            if (p[i].line == "on-line" && p[i + 1].line == "off-line") {
                b.emplace_back(p[i]);
                b.emplace_back(p[i + 1]);
            }
        }
    }
    double tf = 0;
    for (int i = 0; i < (int)b.size(); i += 2) {
        bool next = false, before = false; // whether the first or last record of the people
        if (i + 2 < (int)b.size() && b[i + 2].name == b[i].name) {
            next = true;
        }
        if (i - 2 >= 0 && b[i - 2].name == b[i].name) {
            before = true;
        }
        if (!before) {
            cout << b[i].name << " " << setfill('0') << setw(2) << b[i].M << "\n";
        }
        printf("%02d:%02d:%02d ", b[i].d, b[i].h, b[i].m);
        printf("%02d:%02d:%02d ", b[i + 1].d, b[i + 1].h, b[i + 1].m);
        double f = calfare(b[i], b[i + 1]) / 100;
        cout << b[i + 1].t - b[i].t << " $" << fixed << setprecision(2) << f << "\n";
        tf += f;
        if (!next) {
            cout << "Total amount: $" << fixed << setprecision(2) << tf << "\n";
            tf = 0;
        }
    }

    return 0;
}
// @pintia code=end