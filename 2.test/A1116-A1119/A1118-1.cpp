/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:40:19
 *	modified:	2023-04-03 00:50:34
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805354108403712 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1118 Birds in Forest
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805354108403712
*/

// @pintia code=start
#include <iostream>
#include <numeric>
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

    int count(int n) { // number of connected components
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == i) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int maxBird = 0;
    DisjointSetUnion dsu(1e4 + 1);
    for (int i = 0; i < n; i++) {
        int k, b1;
        cin >> k >> b1;
        maxBird = max(maxBird, b1);
        for (int j = 1; j < k; j++) {
            int b2;
            cin >> b2;
            dsu.unite(b1, b2);
            maxBird = max(maxBird, b2);
        }
    }
    int cnt = dsu.count(maxBird);
    cout << cnt << " " << maxBird << "\n";
    int q;
    cin >> q;
    while (q--) {
        int b1, b2;
        cin >> b1 >> b2;
        if (dsu.find(b1) == dsu.find(b2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end
