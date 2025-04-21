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
    vector<pair<int, int>> rel; // relationship of neighboring regions
    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        rel.emplace_back(a, b);
    }
    int m;
    cin >> m;
    for (int q = 0; q < m; q++) {
        vector<int> d(n);
        unordered_set<int> s; // species
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            s.emplace(d[i]);
        }
        if ((int)s.size() > k) {
            cout << "Error: Too many species.\n";
        } else if ((int)s.size() < k) {
            cout << "Error: Too few species.\n";
        } else {
            bool notSame = true;
            for (auto it : rel) {
                if (d[it.first - 1] == d[it.second - 1]) {
                    // not the same animals in the two neighboring regions
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
