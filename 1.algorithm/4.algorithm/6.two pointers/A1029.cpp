/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 14:14:43
 *	modified:	2023-03-27 14:59:42
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805466364755968 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1029 Median
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805466364755968
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n1;
    cin >> n1;
    vector<long> s1(n1 + 1);
    for (int i = 0; i < n1; i++) {
        cin >> s1[i];
    }
    int n2;
    cin >> n2;
    vector<long> s2(n2 + 1);
    for (int i = 0; i < n2; i++) {
        cin >> s2[i];
    }
    s1[n1] = s2[n2] = INT_MAX;
    int ans = 0, i = 0, j = 0;
    for (int cnt = 0; cnt <= (n1 + n2 - 1) / 2; cnt++) {
        ans = min(s1[i], s2[j]);
        if (s1[i] < s2[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << "\n";

    return 0;
}
// @pintia code=end