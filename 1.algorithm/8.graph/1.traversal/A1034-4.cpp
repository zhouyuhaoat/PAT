/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 14:06:06
 *	modified:	2025-04-16 14:36:38
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
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank; // height of the tree

public:
    string find(string x) {
        if (parent.find(x) == parent.end()) { // not in the set yet
            parent[x] = x;
            rank[x] = 0;
        }
        if (parent[x] != x) { // path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(string x, string y) {
        string rootX = find(x), rootY = find(y);
        if (rootX == rootY) return;
        // union by rank: attach smaller tree under larger tree
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
    unordered_map<string, unordered_map<string, int>> edgeWeights;
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int time;
        cin >> n1 >> n2 >> time;
        weights[n1] += time, weights[n2] += time;
        if (n1 > n2) swap(n1, n2); // ensure consistent key ordering
        edgeWeights[n1][n2] += time;
        dsu.unite(n1, n2);
    }
    unordered_map<string, vector<string>> comps;
    for (auto [person, _] : weights) {
        string root = dsu.find(person);
        comps[root].emplace_back(person);
    }
    map<string, int> gang;
    for (auto [root, members] : comps) {
        if (members.size() <= 2) continue;
        int totalWeight = 0;
        for (size_t i = 0; i < members.size(); i++) {
            for (size_t j = i + 1; j < members.size(); j++) {
                string u = members[i], v = members[j];
                if (u > v) swap(u, v);
                if (edgeWeights.count(u) && edgeWeights[u].count(v)) {
                    totalWeight += edgeWeights[u][v];
                }
            }
        }
        if (totalWeight > k) {
            auto head = max_element(members.begin(), members.end(), [&](string a, string b) {
                return weights[a] != weights[b] ? weights[a] < weights[b] : a > b;
            });
            gang[*head] = members.size();
        }
    }
    cout << gang.size() << "\n";
    for (auto [head, size] : gang) {
        cout << head << " " << size << "\n";
    }

    return 0;
}
// @pintia code=end
