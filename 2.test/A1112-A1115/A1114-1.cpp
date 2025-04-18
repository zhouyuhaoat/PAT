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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct fam { // family
    int id, num;
    double avgEs, avgAr; // estate, area
};

vector<int> f(1e5); // disjoint set union

int find(int x) {
    int a = x;
    while (x != f[x]) {
        x = f[x];
    }
    while (a != f[a]) { // path compression
        int z = a;
        a = f[a], f[z] = x;
    }
    return x;
}

void joint(int a, int b) {
    int fa = find(a), fb = find(b);
    fa > fb ? f[fa] = fb : f[fb] = fa;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, double> es, ar;
    unordered_set<int> p; // persons
    iota(f.begin(), f.end(), 0);
    for (int i = 0; i < n; i++) {
        int id, fa, ma;
        cin >> id >> fa >> ma;
        p.emplace(id);
        if (fa != -1) {
            joint(id, fa);
            p.emplace(fa);
        }
        if (ma != -1) {
            joint(id, ma);
            p.emplace(ma);
        }
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int chi;
            cin >> chi;
            joint(id, chi);
            p.emplace(chi);
        }
        double a, b;
        cin >> a >> b;
        es[id] = a, ar[id] = b;
    }
    unordered_map<int, int> famNum;
    unordered_map<int, double> famEs, famAr;
    for (auto it : p) {
        famNum[find(it)]++;
        if (famEs.count(find(it)) != 0) {
            famEs[find(it)] += es[it], famAr[find(it)] += ar[it];
        } else {
            famEs[find(it)] = es[it], famAr[find(it)] = ar[it];
        }
    }
    vector<fam> ans;
    for (auto it : famNum) {
        ans.emplace_back(fam{it.first, it.second, famEs[it.first] / it.second, famAr[it.first] / it.second});
    }
    sort(ans.begin(), ans.end(), [](fam a, fam b) -> bool {
        if (a.avgAr != b.avgAr) {
            return a.avgAr > b.avgAr;
        } else {
            return a.id < b.id;
        }
    });
    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << setfill('0') << setw(4) << it.id << " " << it.num;
        cout << " " << fixed << setprecision(3) << it.avgEs << " " << it.avgAr << "\n";
    }

    return 0;
}
// @pintia code=end
