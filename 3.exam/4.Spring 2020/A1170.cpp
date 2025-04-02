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
#include <set>
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
        set<int> s; // species
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            s.emplace(d[i]);
        }
        if ((int)s.size() > k) {
            cout << "Error: Too many species.\n";
        } else if ((int)s.size() < k) {
            cout << "Error: Too few species.\n";
        } else {
            bool notsame = true;
            for (auto it : rel) {
                if (d[it.first - 1] == d[it.second - 1]) {
                    // not the same animals in the two neighboring regions
                    notsame = false;
                    break;
                }
            }
            if (notsame) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
// @pintia code=end