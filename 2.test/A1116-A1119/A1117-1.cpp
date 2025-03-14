/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:32:04
 *	modified:	2025-03-14 09:51:00
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805354762715136 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1117 Eddington Number
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805354762715136
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end(), greater<int>());
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] > i + 1) { // E days that one rides more than E miles
            ans = max(ans, i + 1); // maximum
        }
    }
    if (ans == -1) {
        cout << d.back() - 1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
// @pintia code=end