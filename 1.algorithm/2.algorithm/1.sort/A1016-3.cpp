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

struct Record {
    string name;
    int month, day, hh, mm, time;
    string line;
};

int toll[25];
double calFare(Record a) { // calculate fare for a record by accumulating
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
    map<string, vector<Record>> customer; // name -> records
    for (int i = 0; i < n - 1; i++) {
        if (records[i].name == records[i + 1].name) {
            if (records[i].line == "on-line" && records[i + 1].line == "off-line") {
                customer[records[i].name].emplace_back(records[i]);
                customer[records[i].name].emplace_back(records[i + 1]);
            }
        }
    }
    for (auto [name, record] : customer) {
        cout << name << " " << setfill('0') << setw(2) << record[0].month << "\n";
        double total = 0;
        for (int i = 0; i < (int)record.size() - 1; i += 2) {
            printf("%02d:%02d:%02d", record[i].day, record[i].hh, record[i].mm);
            printf(" %02d:%02d:%02d ", record[i + 1].day, record[i + 1].hh, record[i + 1].mm);
            // fare between two records = fare of off-line record - fare of on-line record
            double fare = (calFare(record[i + 1]) - calFare(record[i])) / 100;
            cout << record[i + 1].time - record[i].time << " $" << fixed << setprecision(2) << fare << "\n";
            total += fare;
        }
        cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
    }

    return 0;
}
// @pintia code=end
