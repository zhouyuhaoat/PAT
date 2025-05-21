/*
 *	author:		zhouyuhao
 *	created:	2025-05-16 21:30:30
 *	modified:	2025-05-16 21:40:00
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
#include <unordered_map>
#include <vector>

using namespace std;

struct Car {
    int time;
    string plate, status;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    unordered_map<string, vector<Car>> records; // plate -> cars
    for (int i = 0; i < n; i++) {
        Car temp;
        cin >> temp.plate;
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp.time = hh * 3600 + mm * 60 + ss;
        cin >> temp.status;
        records[temp.plate].emplace_back(temp);
    }
    vector<Car> car;
    int maxParking = -1;
    vector<string> plates; // plates with max parking time
    for (auto [plate, record] : records) {
        sort(record.begin(), record.end(), [](Car a, Car b) {
            return a.time < b.time;
        });
        int parking = 0;
        for (int i = 0; i + 1 < (int)record.size(); i++) { // i < size - 1 <=> i + 1 < size
            if (record[i].status == "in" && record[i + 1].status == "out") { // pair
                car.emplace_back(record[i]), car.emplace_back(record[i + 1]);
                parking += record[i + 1].time - record[i].time;
            }
        }
        if (parking > maxParking) { // better
            maxParking = parking;
            plates.clear();
            plates.emplace_back(plate);
        } else if (parking == maxParking) { // equal
            plates.emplace_back(plate);
        }
    }
    sort(car.begin(), car.end(), [](Car a, Car b) {
        return a.time < b.time;
    });
    int cnt = 0, idx = 0;
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
    sort(plates.begin(), plates.end());
    for (string plate : plates) {
        cout << plate << " ";
    }
    printf("%02d:%02d:%02d\n", maxParking / 3600, maxParking / 60 % 60, maxParking % 60);

    return 0;
}
// @pintia code=end
