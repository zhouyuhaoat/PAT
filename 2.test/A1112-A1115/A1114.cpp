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
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

struct fam { // family
    int id, num;
    double avges, avgar; // estate, area
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
    map<int, double> es, ar;
    set<int> p; // person
    vector<int> pp;
    iota(f.begin(), f.end(), 0);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        pp.emplace_back(id);
        p.emplace(id);
        int fa, ma;
        cin >> fa >> ma;
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
        es[id] = a;
        ar[id] = b;
    }
    map<int, int> famnum;
    for (auto it : p) {
        ++famnum[find(it)];
    }
    map<int, double> fames, famar;
    for (auto it : pp) {
        fames[find(it)] += es[it];
        famar[find(it)] += ar[it];
    }
    vector<fam> ans;
    for (auto it : famnum) {
        ans.emplace_back(fam{it.first, it.second, fames[it.first] / it.second, famar[it.first] / it.second});
    }
    sort(ans.begin(), ans.end(), [](fam a, fam b) -> bool {
        if (a.avgar != b.avgar) {
            return a.avgar > b.avgar;
        } else {
            return a.id < b.id;
        }
    });
    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << setfill('0') << setw(4) << it.id << " " << it.num;
        cout << " " << fixed << setprecision(3) << it.avges << " " << it.avgar << "\n";
    }

    return 0;
}
// @pintia code=end