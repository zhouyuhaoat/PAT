/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 21:21:30
 *	modified:	2024-04-27 21:30:00
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
#include <map>
#include <vector>

using namespace std;

struct per {
    string name;
    int M, d, h, m, t;
    string line;
};

int toll[25];
double calfare(per a) { // calculate fare for a record by accumulating
    double fare = a.d * toll[24] * 60;
    for (int i = 0; i < a.h; i++) {
        fare += toll[i] * 60;
    }
    fare += toll[a.h] * a.m;
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
        scanf("%d:%d:%d:%d", &p[i].M, &p[i].d, &p[i].h, &p[i].m);
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
    map<string, vector<per>> b;
    for (int i = 0; i < n - 1; i++) { // n - 1: avoid out of range
        if (p[i].name == p[i + 1].name) { // pair after sort: on-line & off-line
            if (p[i].line == "on-line" && p[i + 1].line == "off-line") {
                b[p[i].name].emplace_back(p[i]), b[p[i].name].emplace_back(p[i + 1]);
            }
        }
    }
    for (auto it : b) {
        vector<per> c = it.second; // customer
        cout << it.first << " " << setfill('0') << setw(2) << c[0].M << "\n";
        double tf = 0;
        for (int i = 0; i < (int)c.size() - 1; i += 2) {
            printf("%02d:%02d:%02d %02d:%02d:%02d ", c[i].d, c[i].h, c[i].m, c[i + 1].d, c[i + 1].h, c[i + 1].m);
            // fare between two records = fare of off-line record - fare of on-line record
            double f = (calfare(c[i + 1]) - calfare(c[i])) / 100;
            cout << c[i + 1].t - c[i].t << " $" << fixed << setprecision(2) << f << "\n";
            tf += f;
        }
        cout << "Total amount: $" << fixed << setprecision(2) << tf << "\n";
    }

    return 0;
}
// @pintia code=end
