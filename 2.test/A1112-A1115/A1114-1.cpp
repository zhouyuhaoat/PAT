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
    double estate, area; // total -> average
};

class DisjointSetUnion {
private:
    vector<int> f; // father

public:
    DisjointSetUnion(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        return f[x] = find(f[x]); // path compression
    }

    void unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA > rootB) { // union by rank: smaller root to larger root
            f[rootA] = rootB;
        } else {
            f[rootB] = rootA;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    DisjointSetUnion dsu(1e5);
    unordered_map<int, double> estate, area;
    unordered_set<int> persons;
    for (int i = 0; i < n; i++) {
        int id, father, mather;
        cin >> id >> father >> mather;
        persons.emplace(id);
        if (father != -1) {
            dsu.unite(id, father);
            persons.emplace(father);
        }
        if (mather != -1) {
            dsu.unite(id, mather);
            persons.emplace(mather);
        }
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            dsu.unite(id, child);
            persons.emplace(child);
        }
        double a, b;
        cin >> a >> b;
        estate[id] = a, area[id] = b;
    }
    unordered_map<int, fam> families;
    for (int person : persons) {
        int id = dsu.find(person); // dsu to find a connected component
        if (families.count(id) == 0) {
            families[id] = fam{id, 0, 0, 0};
        }
        families[id].num++;
        families[id].estate += estate[person];
        families[id].area += area[person];
    }
    vector<fam> res;
    for (auto [id, family] : families) {
        family.estate /= family.num; // average
        family.area /= family.num;
        res.emplace_back(family);
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
