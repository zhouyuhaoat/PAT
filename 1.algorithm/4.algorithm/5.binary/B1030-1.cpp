/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 10:46:47
 *	modified:	2023-03-27 10:53:12
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805260223102976 pid=994805291311284224 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1030 完美数列
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805291311284224
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, p;
    cin >> n >> p;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), d[i] * p) - d.begin();
        ans = max(ans, j - i);
    }
    cout << ans << "\n";

    return 0;
}
// @pintia code=end