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
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<string, bool> vis;
unordered_map<string, vector<string>> g;
unordered_set<string> persons;
unordered_map<string, int> weights;

void dfs(string u, int& num, int& totalWeight, int& maxWeight, string& head) {
    // update the information between dfs
    vis[u] = true;
    num++;
    totalWeight += weights[u]; // update by each vertex
    if (weights[u] > maxWeight) { // head of gang
        maxWeight = weights[u];
        head = u;
    }
    if (g.count(u) != 0) {
        for (string& v : g[u]) {
            if (!vis[v]) {
                dfs(v, num, totalWeight, maxWeight, head);
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
    }
    map<string, int> gang;
    for (const string& person : persons) {
        if (!vis[person]) {
            int num = 0, totalWeight = 0, maxWeight = -1;
            string head; // the information of connected component
            dfs(person, num, totalWeight, maxWeight, head);
            if (totalWeight > 2 * k && num > 2) { // edge = 2 * vertex
                gang[head] = num;
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
