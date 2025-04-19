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

struct node {
    int id, freq;
    bool operator<(const node& n) const { // override for set
        if (freq != n.freq) {
            return freq > n.freq;
        } else {
            return id < n.id;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq;
    set<node> s;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (!s.empty()) {
            cout << id << ":";
            int cnt = 0;
            for (auto it = s.begin(); cnt++ < k && it != s.end(); it++) {
                cout << " " << it->id;
            }
            cout << "\n";
        }
        auto it = s.find(node{id, freq[id]});
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(node{id, ++freq[id]});
    }

    return 0;
}
// @pintia code=end
