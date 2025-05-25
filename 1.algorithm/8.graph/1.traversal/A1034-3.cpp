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
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> vis;
unordered_map<string, vector<string>> g;
unordered_map<string, int> weights;

pair<int, int> bfs(string src, string& head) {
    int size = 0, totalWeight = 0, maxWeight = -1;
    queue<string> q;
    q.emplace(src);
    vis[src] = true;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        size++;
        totalWeight += weights[u];
        if (weights[u] > maxWeight || (weights[u] == maxWeight && u < head)) {
            maxWeight = weights[u];
            head = u;
        }
        if (g.count(u) != 0) {
            for (string v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }
    return {totalWeight, size};
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int time;
        cin >> n1 >> n2 >> time;
        g[n1].emplace_back(n2), g[n2].emplace_back(n1);
        weights[n1] += time, weights[n2] += time;
    }
    map<string, int> gang;
    for (auto [person, _] : weights) {
        if (vis[person]) continue;
        string head = person;
        auto [totalWeight, size] = bfs(person, head); // connected component by bfs
        if (size > 2 && totalWeight > 2 * k) {
            gang[head] = size;
        }
    }
    cout << gang.size() << "\n";
    for (auto [head, size] : gang) {
        cout << head << " " << size << "\n";
    }

    return 0;
}
// @pintia code=end
