/*
 *	author:		zhouyuhao
 *	created:	2023-03-24 20:05:53
 *	modified:	2023-03-24 22:14:14
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    int month, day, hh, mm;
    string line;
};

int toll[24], cnt = 0;
double calFare(per a, per b) {
    double fare = 0;
    while (a.day != b.day || a.hh != b.hh || a.mm != b.mm) {
        fare += toll[a.hh];
        a.mm++; // minute by minute
        cnt++;
        if (a.mm == 60) {
            a.mm = 0;
            a.hh++;
            if (a.hh == 24) {
                a.hh = 0;
                a.day++;
            }
        }
    }
    return fare;
}

int main(int argc, char const *argv[]) {

    for (int i = 0; i < 24; i++) {
        cin >> toll[i];
    }
    int n;
    cin >> n;
    vector<per> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hh, &data[i].mm);
        cin >> data[i].line;
    }
    sort(data.begin(), data.end(), [](per a, per b) -> bool {
        if (a.name != b.name) {
            return a.name < b.name;
        } else if (a.day != b.day) {
            return a.day < b.day;
        } else if (a.hh != b.hh) {
            return a.hh < b.hh;
        } else {
            return a.mm < b.mm;
        }
    });
    vector<per> person;
    for (int i = 0; i < n - 1; i++) {
        if (data[i].name == data[i + 1].name) {
            if (data[i].line == "on-line" && data[i + 1].line == "off-line") {
                person.emplace_back(data[i]), person.emplace_back(data[i + 1]);
            }
        }
    }
    double total = 0;
    for (int i = 0; i < (int)person.size(); i += 2) {
        bool first = true, last = true;
        if (i - 2 >= 0 && person[i - 2].name == person[i].name) {
            first = false;
        }
        if (i + 2 < (int)person.size() && person[i + 2].name == person[i].name) {
            last = false;
        }
        if (first) {
            cout << person[i].name << " " << setfill('0') << setw(2) << person[i].month << "\n";
        }
        printf("%02d:%02d:%02d", person[i].day, person[i].hh, person[i].mm);
        printf(" %02d:%02d:%02d ", person[i + 1].day, person[i + 1].hh, person[i + 1].mm);
        double fare = calFare(person[i], person[i + 1]) / 100;
        cout << cnt << " $" << fixed << setprecision(2) << fare << "\n";
        cnt = 0;
        total += fare;
        if (last) {
            cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
            total = 0;
        }
    }

    return 0;
}
// @pintia code=end
