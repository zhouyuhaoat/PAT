/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 22:33:18
 *	modified:	2023-03-26 23:18:02
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805398257647616 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1071 Speech Patterns
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805398257647616
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    unordered_map<string, int> cnt;
    while (cin >> s) {
        string t;
        for (char ch : s) {
            if (isalnum(ch)) {
                t += tolower(ch);
            } else {
                if (!t.empty()) {
                    cnt[t]++;
                    t.clear();
                }
            }
        }
        if (!t.empty()) { // the last word
            cnt[t]++;
        }
    }
    auto it = max_element(cnt.begin(), cnt.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    });
    cout << it->first << " " << it->second << "\n"; // pattern, count

    return 0;
}
// @pintia code=end
