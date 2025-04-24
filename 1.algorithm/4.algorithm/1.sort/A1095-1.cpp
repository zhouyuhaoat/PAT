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

struct car {
    int time;
    string plate, status;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<car> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].plate;
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        data[i].time = h * 3600 + m * 60 + s;
        cin >> data[i].status;
    }
    sort(data.begin(), data.end(), [](car a, car b) -> bool {
        if (a.plate != b.plate) {
            return a.plate < b.plate;
        } else {
            return a.time < b.time;
        }
    });
    vector<car> cars;
    map<string, int> parking; // plate -> time
    int maxParking = -1;
    for (int i = 0; i < n - 1; i++) { // pair after sort: in & out; n - 1: avoid out of range
        if (data[i].plate == data[i + 1].plate && data[i].status == "in" && data[i + 1].status == "out") {
            cars.emplace_back(data[i]), cars.emplace_back(data[i + 1]);
            parking[data[i].plate] += data[i + 1].time - data[i].time;
            maxParking = max(parking[data[i].plate], maxParking);
        }
    }
    sort(cars.begin(), cars.end(), [](car a, car b) -> bool {
        return a.time < b.time;
    });
    int cnt = 0, idx = 0;
    for (int q = 0; q < k; q++) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int time = h * 3600 + m * 60 + s;
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
