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
    int month, day, hh, mm, time;
    string line;
};

int toll[25];
double calFare(per a, per b) { // calculate fare between two records
    double fare = (b.day - a.day) * toll[24] * 60;
    int symbol = 1;
    if (a.hh * 60 + a.mm > b.hh * 60 + b.mm) {
        swap(a, b);
        symbol = -1;
    }
    for (int i = a.hh + 1; i < b.hh; i++) {
        fare += symbol * toll[i] * 60;
    }
    if (a.hh == b.hh) {
        fare += symbol * (b.mm - a.mm) * toll[a.hh];
    } else { // cross the hour
        fare += symbol * (60 - a.mm) * toll[a.hh];
        fare += symbol * b.mm * toll[b.hh];
    }
    return fare;
}

int main(int argc, char const *argv[]) {

    for (int i = 0; i < 24; i++) { // rate structure
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
    vector<per> person;
    for (int i = 0; i < n - 1; i++) { // n - 1: avoid out of range
        if (data[i].name == data[i + 1].name) { // pair after sort: on-line & off-line
            if (data[i].line == "on-line" && data[i + 1].line == "off-line") {
                person.emplace_back(data[i]), person.emplace_back(data[i + 1]);
            }
        }
    }
    double total = 0; // total fare of each person
    for (int i = 0; i < (int)person.size(); i += 2) {
        bool first = true, last = true; // whether the first or last record of the person
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
        cout << person[i + 1].time - person[i].time << " $" << fixed << setprecision(2) << fare << "\n";
        total += fare;
        if (last) {
            cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
            total = 0;
        }
    }

    return 0;
}
// @pintia code=end
