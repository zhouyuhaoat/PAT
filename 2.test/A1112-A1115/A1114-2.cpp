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

struct fam {
    int id, num;
    double estate, area;
};

unordered_map<int, double> estate, area;
unordered_set<int> persons;
unordered_map<int, bool> vis;
unordered_map<int, vector<int>> g;

fam bfs(int src) { // bfs to find a connected component
    queue<int> q;
    q.emplace(src);
    vis[src] = true;
    fam family = {10000, 0, 0.0, 0.0};
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        family.id = min(family.id, u);
        family.num++;
        family.estate += estate[u], family.area += area[u];
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.emplace(v);
            }
        }
    }
    family.estate /= family.num, family.area /= family.num;
    return family;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, father, mather;
        cin >> id >> father >> mather;
        persons.emplace(id);
        if (father != -1) {
            g[id].emplace_back(father), g[father].emplace_back(id);
            persons.emplace(father);
        }
        if (mather != -1) {
            g[id].emplace_back(mather), g[mather].emplace_back(id);
            persons.emplace(mather);
        }
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            g[id].emplace_back(child), g[child].emplace_back(id);
            persons.emplace(child);
        }
        double a, b;
        cin >> a >> b;
        estate[id] = a, area[id] = b;
    }
    vector<fam> res;
    for (int person : persons) {
        if (!vis[person]) {
            res.emplace_back(bfs(person));
        }
    }
    sort(res.begin(), res.end(), [](fam a, fam b) -> bool {
        if (a.area != b.area) {
            return a.area > b.area;
        } else {
            return a.id < b.id;
        }
    });
    cout << res.size() << "\n";
    for (auto family : res) {
        cout << setfill('0') << setw(4) << family.id << " " << family.num;
        cout << " " << fixed << setprecision(3) << family.estate << " " << family.area << "\n";
    }

    return 0;
}
// @pintia code=end
