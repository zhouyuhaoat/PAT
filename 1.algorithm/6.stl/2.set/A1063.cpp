/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 22:10:10
 *	modified:	2023-03-26 22:17:22
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805409175420928 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1063 Set Similarity
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805409175420928
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<set<int>> s(n + 1);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            s[i + 1].emplace(num);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (auto it : s[a]) {
            if (s[b].find(it) != s[b].end()) {
                ++cnt;
            }
        }
        double r = (double)cnt / (s[a].size() + s[b].size() - cnt) * 100;
        cout << fixed << setprecision(1) << r << "%\n";
    }

    return 0;
}
// @pintia code=end