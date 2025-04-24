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
    int month, day, hh, mm, time;
    string line;
};

int toll[25];
double calFare(per a) { // calculate fare for a record with accumulating
    double fare = a.day * toll[24] * 60;
    for (int i = 0; i < a.hh; i++) {
        fare += toll[i] * 60;
    }
    fare += toll[a.hh] * a.mm;
    return fare;
}

int main(int argc, char const *argv[]) {

    for (int i = 0; i < 24; i++) {
        cin >> toll[i];
        toll[24] += toll[i];
    }
    int n;
    cin >> n;
    vector<per> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hh, &data[i].mm);
        data[i].time = data[i].day * 24 * 60 + data[i].hh * 60 + data[i].mm;
        cin >> data[i].line;
    }
    sort(data.begin(), data.end(), [](per a, per b) -> bool {
        if (a.name != b.name) {
            return a.name < b.name;
        } else {
            return a.time < b.time;
        }
    });
    map<string, vector<per>> person;
    for (int i = 0; i < n - 1; i++) {
        if (data[i].name == data[i + 1].name) {
            if (data[i].line == "on-line" && data[i + 1].line == "off-line") {
                person[data[i].name].emplace_back(data[i]), person[data[i].name].emplace_back(data[i + 1]);
            }
        }
    }
    for (auto [name, records] : person) {
        cout << name << " " << setfill('0') << setw(2) << records[0].month << "\n";
        double total = 0;
        for (int i = 0; i < (int)records.size() - 1; i += 2) {
            printf("%02d:%02d:%02d", records[i].day, records[i].hh, records[i].mm);
            printf(" %02d:%02d:%02d ", records[i + 1].day, records[i + 1].hh, records[i + 1].mm);
            // fare between two records = fare of off-line record - fare of on-line record
            double fare = (calFare(records[i + 1]) - calFare(records[i])) / 100;
            cout << records[i + 1].time - records[i].time << " $" << fixed << setprecision(2) << fare << "\n";
            total += fare;
        }
        cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
    }

    return 0;
}
// @pintia code=end
