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

struct Item {
    int id, freq;
    bool operator<(const Item& other) const { // member function
        if (freq != other.freq) {
            return freq > other.freq;
        } else {
            return id < other.id;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq; // id -> frequency
    set<Item> rec; // recommendation
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (i > 0) {
            cout << id << ":";
            int cnt = 0;
            for (auto it = rec.begin(); it != rec.end() && cnt++ < k; it++) { // top k
                cout << " " << it->id;
            }
            cout << "\n";
        }
        auto it = rec.find(Item{id, freq[id]});
        if (it != rec.end()) {
            rec.erase(it);
        }
        rec.emplace(Item{id, ++freq[id]});
    }

    return 0;
}
// @pintia code=end
