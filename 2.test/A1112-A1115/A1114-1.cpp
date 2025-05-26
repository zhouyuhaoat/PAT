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

struct Family {
    int id, size;
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
        if (rootA < rootB) { // union by rank: larger id -> smaller id
            swap(rootA, rootB);
        }
        f[rootA] = rootB;
    }
};

DisjointSetUnion dsu(1e5);
unordered_map<int, double> estate, area;
unordered_set<int> persons;

void addRelative(int id, int relative) {
    if (relative != -1) {
        dsu.unite(id, relative);
        persons.emplace(relative);
    }
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
    unordered_map<int, Family> families;
    for (int person : persons) {
        int id = dsu.find(person); // dsu to find a connected component
        if (families.count(id) == 0) {
            families[id] = Family{id, 0, 0, 0};
        }
        families[id].size++;
        families[id].estate += estate[person], families[id].area += area[person];
    }
    vector<Family> res;
    for (auto [id, family] : families) {
        family.estate /= family.size, family.area /= family.size; // average
        res.emplace_back(family);
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
