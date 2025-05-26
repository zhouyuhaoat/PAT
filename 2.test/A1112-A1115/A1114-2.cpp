/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 14:59:06
 *	modified:	2023-04-04 09:06:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805356599820288 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1114 Family Property
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805356599820288
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Family {
    int id, size;
    double estate, area;
};

unordered_map<int, double> estate, area;
unordered_set<int> persons;
unordered_map<int, bool> vis;
unordered_map<int, vector<int>> g;

void addRelative(int id, int relative) {
    if (relative != -1) {
        g[id].emplace_back(relative), g[relative].emplace_back(id);
        persons.emplace(relative);
    }
}

Family bfs(int src) { // bfs to find a connected component
    queue<int> q;
    q.emplace(src);
    vis[src] = true;
    Family family{10000, 0, 0.0, 0.0};
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        family.id = min(family.id, u);
        family.size++;
        family.estate += estate[u], family.area += area[u];
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.emplace(v);
            }
        }
    }
    family.estate /= family.size, family.area /= family.size;
    return family;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, father, mother;
        cin >> id >> father >> mother;
        persons.emplace(id);
        addRelative(id, father), addRelative(id, mother);
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            addRelative(id, child);
        }
        cin >> estate[id] >> area[id];
    }
    vector<Family> res;
    for (int person : persons) {
        if (!vis[person]) {
            res.emplace_back(bfs(person));
        }
    }
    sort(res.begin(), res.end(), [](Family a, Family b) {
        if (a.area != b.area) {
            return a.area > b.area;
        } else {
            return a.id < b.id;
        }
    });
    cout << res.size() << "\n";
    for (auto family : res) {
        cout << setfill('0') << setw(4) << family.id << " " << family.size;
        cout << " " << fixed << setprecision(3) << family.estate << " " << family.area << "\n";
    }

    return 0;
}
// @pintia code=end
