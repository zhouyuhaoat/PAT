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
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    getline(cin, s);
    unordered_map<string, int> cnt;
    int maxCnt = -1;
    string t;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isalnum(s[i])) {
            t += tolower(s[i]);
        }
        if (!isalnum(s[i]) || i == (int)s.size() - 1) { // end of a word
            if (!t.empty() && ++cnt[t] > maxCnt) {
                maxCnt = cnt[t];
            }
            t.clear();
        }
    }
    for (auto [pattern, count] : cnt) {
        if (count == maxCnt) {
            cout << pattern << " " << count << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end
