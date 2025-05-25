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
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<string, bool> vis;
unordered_map<string, vector<string>> g;
unordered_set<string> persons;
unordered_map<string, int> weights; // weight of each person
unordered_map<string, unordered_map<string, int>> edgeWeights; // weight between two persons
vector<vector<string>> comps; // components

void dfs(string u, vector<string>& comp) {
    vis[u] = true;
    comp.emplace_back(u);
    if (g.count(u) != 0) {
        for (string v : g[u]) {
            if (!vis[v]) {
                dfs(v, comp);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int time;
        cin >> n1 >> n2 >> time;
        persons.emplace(n1), persons.emplace(n2);
        g[n1].emplace_back(n2), g[n2].emplace_back(n1);
        weights[n1] += time, weights[n2] += time;
        edgeWeights[n1][n2] += time, edgeWeights[n2][n1] += time;
    }
    for (const string& person : persons) { // const since unordered_set
        if (!vis[person]) {
            vector<string> comp; // connected component by dfs
            dfs(person, comp);
            comps.emplace_back(comp);
        }
    }
    map<string, int> gang;
    for (auto comp : comps) {
        if (comp.size() > 2) {
            int totalWeight = 0; // each pair of people in the component
            for (size_t i = 0; i < comp.size(); i++) {
                for (size_t j = i + 1; j < comp.size(); j++) {
                    string u = comp[i], v = comp[j];
                    if (edgeWeights.count(u) != 0 && edgeWeights[u].count(v) != 0) {
                        totalWeight += edgeWeights[u][v];
                    }
                }
            }
            if (totalWeight > k) { // gang
                string head = comp[0];
                int maxWeight = weights[head];
                for (string person : comp) {
                    if (weights[person] > maxWeight || (weights[person] == maxWeight && person < head)) {
                        head = person;
                        maxWeight = weights[person];
                    }
                }
                gang[head] = comp.size(); // head of gang
            }
        }
    }
    cout << gang.size() << "\n";
    for (auto [head, size] : gang) {
        cout << head << " " << size << "\n";
    }

    return 0;
}
// @pintia code=end
