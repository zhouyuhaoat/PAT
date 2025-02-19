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
    string id;
    string time;
    string status;
};

int trans(string a) {
    return stoi(a.substr(0, 2)) * 3600 + stoi(a.substr(3, 2)) * 60 + stoi(a.substr(6, 2));
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<car> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].id >> c[i].time >> c[i].status;
    }
    sort(c.begin(), c.end(), [](car a, car b) -> bool {
        if (a.id != b.id) {
            return a.id < b.id;
        } else {
            return a.time < b.time;
        }
    });
    vector<car> cp;
    map<string, int> during;
    int maxduring = -1;
    for (int i = 0; i < n; i++) { // pair after sort: in & out
        if (c[i].id == c[i + 1].id && c[i].status == "in" && c[i + 1].status == "out") {
            cp.emplace_back(c[i]);
            cp.emplace_back(c[i + 1]);
            during[c[i].id] += trans(c[i + 1].time) - trans(c[i].time);
            maxduring = max(during[c[i].id], maxduring);
        }
    }
    sort(cp.begin(), cp.end(), [](car a, car b) -> bool {
        return a.time < b.time;
    });
    int cnt = 0, idx = 0;
    for (int q = 0; q < k; q++) {
        string time;
        cin >> time;
        for (; idx < (int)cp.size(); idx++) {
            if (cp[idx].time <= time) {
                if (cp[idx].status == "in") {
                    ++cnt;
                } else {
                    --cnt;
                }
            } else {
                break;
            }
        }
        cout << cnt << "\n";
    }
    for (auto it : during) {
        if (it.second == maxduring) {
            cout << it.first << " ";
        }
    }
    printf("%02d:%02d:%02d\n", maxduring / 3600, maxduring / 60 % 60, maxduring % 60);

    return 0;
}
// @pintia code=end