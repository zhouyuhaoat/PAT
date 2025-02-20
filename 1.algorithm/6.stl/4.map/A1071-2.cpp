/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 13:17:00
 *	modified:	2024-05-04 13:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805398257647616 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1071 Speech Patterns
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805398257647616
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    getline(cin, s);
    map<string, int> count;
    string t;
    int cnt = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isalnum(s[i])) {
            t += tolower(s[i]);
        }
        if (!isalnum(s[i]) || i == (int)s.size() - 1) {
            if (!t.empty() && ++count[t] > cnt) {
                cnt = count[t];
            }
            t = "";
        }
    }
    for (auto it : count) {
        if (it.second == cnt) {
            cout << it.first << " " << cnt << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end