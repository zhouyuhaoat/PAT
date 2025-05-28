/*
 *	author:		zhouyuhao
 *	created:	2023-04-06 08:34:34
 *	modified:	2023-04-06 08:49:05
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1621700071370862592 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1170 Safari Park
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1621700071370862592
*/

// @pintia code=start
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, r, k;
    cin >> n >> r >> k;
    vector<pair<int, int>> relate; // relationship of neighboring regions
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        relate.emplace_back(u, v);
    }
    int m;
    cin >> m;
    for (int q = 0; q < m; q++) {
        vector<int> data(n + 1);
        unordered_set<int> species;
        for (int i = 1; i <= n; i++) {
            cin >> data[i];
            species.emplace(data[i]);
        }
        if ((int)species.size() > k) {
            cout << "Error: Too many species.\n";
        } else if ((int)species.size() < k) {
            cout << "Error: Too few species.\n";
        } else {
            bool notSame = true;
            for (auto [u, v] : relate) {
                if (data[u] == data[v]) {
                    notSame = false;
                    break;
                }
            }
            notSame ? cout << "Yes\n" : cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end
