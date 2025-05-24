/*
 *	author:		zhouyuhao
 *	created:	2025-04-25 22:37:25
 *	modified:	2025-04-25 23:36:56
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805361586847744 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1107 Social Clusters
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805361586847744
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

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
        if (rootA != rootB) {
            f[rootA] = rootB;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    DisjointSetUnion dsu(n + 1);
    unordered_map<int, int> hobby; // hobby id -> cluster id
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        getchar();
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            if (hobby[id] == 0) { // the first person who has this hobby
                hobby[id] = i + 1;
            }
            dsu.unite(i + 1, hobby[id]);
        }
    }
    unordered_map<int, int> cnt; // cluster id -> count
    for (int i = 1; i <= n; i++) {
        cnt[dsu.find(i)]++;
    }
    vector<int> clu(cnt.size()); // the values of a map -> vector
    transform(cnt.begin(), cnt.end(), clu.begin(), [](pair<int, int> p) {
        return p.second;
    });
    sort(clu.begin(), clu.end(), greater<int>());
    cout << clu.size() << "\n";
    for (int i = 0; i < (int)clu.size(); i++) {
        cout << clu[i];
        i < (int)clu.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
