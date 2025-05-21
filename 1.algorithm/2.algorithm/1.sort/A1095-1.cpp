/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 17:35:20
 *	modified:	2023-03-25 17:56:35
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    int time;
    string plate, status;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<Car> record(n);
    for (int i = 0; i < n; i++) {
        cin >> record[i].plate;
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        record[i].time = hh * 3600 + mm * 60 + ss;
        cin >> record[i].status;
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
    map<string, int> parking; // plate -> parking time
    for (int i = 0; i < n - 1; i++) { // n - 1: avoid out of range
        if (record[i].plate == record[i + 1].plate) { // pair after sort
            if (record[i].status == "in" && record[i + 1].status == "out") {
                car.emplace_back(record[i]), car.emplace_back(record[i + 1]);
                parking[record[i].plate] += record[i + 1].time - record[i].time;
                maxParking = max(parking[record[i].plate], maxParking);
            }
        }
    }
    sort(car.begin(), car.end(), [](Car a, Car b) {
        return a.time < b.time;
    });
    int cnt = 0, idx = 0; // avoid search from the beginning for each query
    for (int q = 0; q < k; q++) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss;
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
