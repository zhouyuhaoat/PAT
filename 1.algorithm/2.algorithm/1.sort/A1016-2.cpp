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

struct Record {
    string name;
    int month, day, hh, mm;
    string line;
};

int toll[24];
double calFare(Record a, Record b, int& time) { // minute by minute
    double fare = 0;
    while (a.day != b.day || a.hh != b.hh || a.mm != b.mm) {
        fare += toll[a.hh];
        time++;
        if (++a.mm == 60) {
            a.mm = 0;
            if (++a.hh == 24) {
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
    vector<Record> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i].name;
        scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hh, &records[i].mm);
        cin >> records[i].line;
    }
    sort(records.begin(), records.end(), [](Record a, Record b) {
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
    vector<Record> record;
    for (int i = 0; i < n - 1; i++) {
        if (records[i].name == records[i + 1].name) {
            if (records[i].line == "on-line" && records[i + 1].line == "off-line") {
                record.emplace_back(records[i]), record.emplace_back(records[i + 1]);
            }
        }
    }
    double total = 0;
    for (int i = 0; i < (int)record.size(); i += 2) {
        bool first = true, last = true;
        if (i - 2 >= 0 && record[i - 2].name == record[i].name) {
            first = false;
        }
        if (i + 2 < (int)record.size() && record[i + 2].name == record[i].name) {
            last = false;
        }
        if (first) {
            cout << record[i].name << " " << setfill('0') << setw(2) << record[i].month << "\n";
        }
        printf("%02d:%02d:%02d", record[i].day, record[i].hh, record[i].mm);
        printf(" %02d:%02d:%02d ", record[i + 1].day, record[i + 1].hh, record[i + 1].mm);
        int time = 0;
        double fare = calFare(record[i], record[i + 1], time) / 100;
        cout << time << " $" << fixed << setprecision(2) << fare << "\n";
        total += fare;
        if (last) {
            cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
            total = 0;
        }
    }

    return 0;
}
// @pintia code=end
