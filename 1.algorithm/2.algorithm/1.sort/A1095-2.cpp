/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 11:20:00
 *	modified:	2024-04-28 11:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805371602845696 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1095 Cars on Campus
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805371602845696
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Car {
    string plate, time, status;
};

int convert(string time) {
    int hh, mm, ss;
    hh = stoi(time.substr(0, 2)), mm = stoi(time.substr(3, 2)), ss = stoi(time.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<Car> record(n);
    for (int i = 0; i < n; i++) {
        cin >> record[i].plate >> record[i].time >> record[i].status;
    }
    sort(record.begin(), record.end(), [](Car a, Car b) {
        if (a.plate != b.plate) {
            return a.plate < b.plate;
        } else {
            return a.time < b.time;
        }
    });
    vector<Car> car;
    int maxParking = -1;
    map<string, int> parking;
    for (int i = 0; i < n - 1; i++) {
        if (record[i].plate == record[i + 1].plate) {
            if (record[i].status == "in" && record[i + 1].status == "out") {
                car.emplace_back(record[i]), car.emplace_back(record[i + 1]);
                parking[record[i].plate] += convert(record[i + 1].time) - convert(record[i].time);
                maxParking = max(parking[record[i].plate], maxParking);
            }
        }
    }
    sort(car.begin(), car.end(), [](Car a, Car b) {
        return a.time < b.time;
    });
    int cnt = 0, idx = 0;
    for (int q = 0; q < k; q++) {
        string time;
        cin >> time;
        for (; idx < (int)car.size(); idx++) {
            if (car[idx].time <= time) {
                car[idx].status == "in" ? cnt++ : cnt--;
            } else {
                break;
            }
        }
        cout << cnt << "\n";
    }
    for (auto [plate, time] : parking) {
        if (time == maxParking) {
            cout << plate << " ";
        }
    }
    printf("%02d:%02d:%02d\n", maxParking / 3600, maxParking / 60 % 60, maxParking % 60);

    return 0;
}
// @pintia code=end
