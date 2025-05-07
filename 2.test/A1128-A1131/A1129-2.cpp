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

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq;
    set<pair<int, int>, cmp> s; // pair: id, frequency
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (!s.empty()) {
            cout << id << ":";
            int cnt = 0;
            for (auto it = s.begin(); cnt++ < k && it != s.end(); it++) {
                cout << " " << it->first;
            }
            cout << "\n";
        }
        auto it = s.find({id, freq[id]});
        if (it != s.end()) {
            s.erase(it);
        }
        s.emplace(id, ++freq[id]);
    }

    return 0;
}
// @pintia code=end
