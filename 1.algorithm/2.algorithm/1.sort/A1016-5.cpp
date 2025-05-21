/*
 *	author:		zhouyuhao
 *	created:	2025-05-16 21:30:30
 *	modified:	2025-05-16 21:40:00
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
    string name, date;
    int month, day, hh, mm, time;
    string line;
};

int toll[25];
double calFare(Record a) {
    double fare = a.day * toll[24] * 60;
    fare += toll[a.hh] * 60;
    fare += (toll[a.hh + 1] - toll[a.hh]) * a.mm;
    return fare;
}

int main(int argc, char const *argv[]) {

    for (int i = 1; i <= 24; i++) {
        cin >> toll[i];
        toll[i] += toll[i - 1];
    }
    int n;
    cin >> n;
    map<string, vector<Record>> records; // name -> (valid + invalid) records
    for (int i = 0; i < n; i++) {
        Record temp;
        cin >> temp.name >> temp.date >> temp.line;
        sscanf(temp.date.c_str(), "%d:%d:%d:%d", &temp.month, &temp.day, &temp.hh, &temp.mm);
        temp.date = temp.date.substr(3); // data format: month:day:hh:mm -> day:hh:mm
        temp.time = temp.day * 24 * 60 + temp.hh * 60 + temp.mm;
        records[temp.name].emplace_back(temp);
    }
    for (auto [name, record] : records) {
        sort(record.begin(), record.end(), [](Record a, Record b) {
            return a.time < b.time;
        });
        double total = 0;
        for (int i = 0; i + 1 < (int)record.size(); i++) { // i < size - 1 <=> i + 1 < size
            Record a = record[i], b = record[i + 1]; // rename
            if (a.line == "on-line" && b.line == "off-line") { // pair
                if (total == 0) { // the first record
                    cout << name << " " << setfill('0') << setw(2) << a.month << "\n";
                }
                cout << a.date << " " << b.date << " ";
                double fare = (calFare(b) - calFare(a)) / 100;
                cout << b.time - a.time << " $" << fixed << setprecision(2) << fare << "\n";
                total += fare;
            }
        }
        if (total != 0) { // at least one record
            cout << "Total amount: $" << fixed << setprecision(2) << total << "\n";
        }
    }

    return 0;
}
// @pintia code=end
