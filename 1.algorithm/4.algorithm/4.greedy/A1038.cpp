/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 10:47:08
 *	modified:	2023-03-26 11:10:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805449625288704 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1038 Recover the Smallest Number
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805449625288704
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [](string a, string b) {
        // each pair of strings is compared by their concatenation
        return a + b < b + a;
    });
    string r;
    for (auto it : s) {
        r += it;
    }
    while (r.size() > 1 && r[0] == '0') { // leading zeros
        r.erase(0, 1);
    }
    cout << r << "\n";

    return 0;
}
// @pintia code=end