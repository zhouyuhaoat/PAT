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

struct car {
    string plate, time, status;
};

int convert(string a) {
    return stoi(a.substr(0, 2)) * 3600 + stoi(a.substr(3, 2)) * 60 + stoi(a.substr(6, 2));
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<car> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].plate >> data[i].time >> data[i].status;
    }
    sort(data.begin(), data.end(), [](car a, car b) -> bool {
        if (a.plate != b.plate) {
            return a.plate < b.plate;
        } else {
            return a.time < b.time;
        }
    });
    vector<car> cars;
    map<string, int> parking;
    int maxParking = -1;
    for (int i = 0; i < n - 1; i++) {
        if (data[i].plate == data[i + 1].plate && data[i].status == "in" && data[i + 1].status == "out") {
            cars.emplace_back(data[i]), cars.emplace_back(data[i + 1]);
            parking[data[i].plate] += convert(data[i + 1].time) - convert(data[i].time);
            maxParking = max(parking[data[i].plate], maxParking);
        }
    }
    sort(cars.begin(), cars.end(), [](car a, car b) -> bool {
        return a.time < b.time;
    });
    int cnt = 0, idx = 0;
    for (int q = 0; q < k; q++) {
        string time;
        cin >> time;
        for (; idx < (int)cars.size(); idx++) {
            if (cars[idx].time <= time) {
                cars[idx].status == "in" ? cnt++ : cnt--;
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
