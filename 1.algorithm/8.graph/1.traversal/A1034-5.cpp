/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 10:40:09
 *	modified:	2025-04-16 13:00:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805456881434624 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1034 Head of a Gang
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805456881434624
*/

// @pintia code=start
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

public:
    string find(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 0;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(string x, string y) {
        string rootX = find(x), rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    DisjointSetUnion dsu;
    unordered_map<string, int> weights;
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int time;
        cin >> n1 >> n2 >> time;
        dsu.unite(n1, n2);
        weights[n1] += time, weights[n2] += time;
    }
    unordered_map<string, vector<string>> comps;
    for (auto [person, _] : weights) {
        comps[dsu.find(person)].emplace_back(person);
    }
    map<string, int> gang;
    for (auto [root, members] : comps) {
        if (members.size() <= 2) continue;
        int totalWeight = 0;
        string head = members[0];
        for (auto person : members) {
            totalWeight += weights[person];
            if (weights[person] > weights[head] || (weights[person] == weights[head] && person < head)) {
                head = person;
            }
        }
        if (totalWeight > 2 * k) {
            gang[head] = members.size();
        }
    }
    cout << gang.size() << "\n";
    for (auto [head, size] : gang) {
        cout << head << " " << size << "\n";
    }

    return 0;
}
// @pintia code=end
