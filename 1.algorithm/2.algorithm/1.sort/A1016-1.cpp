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

struct Record {
    string name;
    int month, day, hh, mm, time;
    string line;
};

int toll[25];
double calFare(Record a, Record b) { // calculate fare between two records
    double fare = (b.day - a.day) * toll[24] * 60;
    int symbol = 1; // ensure a is earlier than b
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
    vector<Record> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i].name;
        scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hh, &records[i].mm);
        records[i].time = records[i].day * 24 * 60 + records[i].hh * 60 + records[i].mm;
        cin >> records[i].line;
    }
    sort(records.begin(), records.end(), [](Record a, Record b) {
        if (a.name != b.name) {
            return a.name < b.name;
        } else {
            return a.time < b.time;
        }
    });
    vector<Record> record;
    for (int i = 0; i < n - 1; i++) { // n - 1: avoid out of range
        if (records[i].name == records[i + 1].name) { // pair after sort
            if (records[i].line == "on-line" && records[i + 1].line == "off-line") {
                record.emplace_back(records[i]), record.emplace_back(records[i + 1]);
            }
        }
    }
    double total = 0; // total fare of each customer
    for (int i = 0; i < (int)record.size(); i += 2) {
        bool first = true, last = true; // assume the first and last record of the customer
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
        double fare = calFare(record[i], record[i + 1]) / 100;
        cout << record[i + 1].time - record[i].time << " $" << fixed << setprecision(2) << fare << "\n";
        total += fare;
        if (last) {
            cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
            total = 0;
        }
    }

    return 0;
}
// @pintia code=end
