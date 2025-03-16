/*
 *	author:		zhouyuhao
 *	created:	2024-05-07 21:15:56
 *	modified:	2024-05-07 21:38:41
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805348471259136 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1129 Recommendation System
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805348471259136
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    int id, freq; // id, frequency
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    map<int, int> cnt, recing; // current recommendation
    map<int, bool> reced; // has been recommended
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        vector<node> rec;
        for (auto it : recing) {
            rec.emplace_back(node{it.first, it.second});
        }
        if (!recing.empty()) {
            cout << id << ": ";
            sort(rec.begin(), rec.end(), [](node a, node b) {
                if (a.freq != b.freq) {
                    return a.freq > b.freq;
                } else {
                    return a.id < b.id;
                }
            });
            int size = min((int)rec.size(), k);
            for (int j = 0; j < size; j++) {
                cout << rec[j].id;
                j < size - 1 ? cout << " " : cout << "\n";
            }
        }
        ++cnt[id];
        if ((int)recing.size() < k) {
            recing[id] = cnt[id];
            reced[id] = true;
            continue;
        }
        if (reced[id]) {
            recing[id] = cnt[id];
        } else { // if necessary, remove the last one, add the current one
            if (cnt[id] > rec.back().freq || (cnt[id] == rec.back().freq && id < rec.back().id)) {
                recing[id] = cnt[id];
                reced[id] = true;
                recing.erase(recing.find(rec.back().id));
                reced[rec.back().id] = false;
            }
        }
    }

    return 0;
}
// @pintia code=end