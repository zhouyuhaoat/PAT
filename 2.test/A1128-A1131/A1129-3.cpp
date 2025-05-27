/*
 *	author:		zhouyuhao
 *	created:	2024-05-14 18:59:56
 *	modified:	2024-05-14 19:38:41
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805348471259136 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1129 Recommendation System
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805348471259136
*/

// @pintia code=start
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

struct cmp { // functor
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main(int argc, char const *argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq;
    set<pair<int, int>, cmp> rec; // {id, frequency}
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (!rec.empty()) {
            cout << id << ":";
            for (auto it : rec) {
                cout << " " << it.first;
            }
            cout << "\n";
        }
        auto it = rec.find({id, freq[id]});
        if (it != rec.end()) {
            rec.erase(it);
        }
        rec.emplace(id, ++freq[id]);
        if ((int)rec.size() > k) {
            rec.erase(prev(rec.end())); // remove the last element
        }
    }

    return 0;
}
// @pintia code=end
