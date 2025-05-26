/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 19:48:22
 *	modified:	2023-04-02 20:09:08
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805357933608960 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1112 Stucked Keyboard
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805357933608960
*/

// @pintia code=start
#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[]) {

    int k; // stuck: appear repeatedly for k times
    string s;
    cin >> k >> s;
    unordered_set<char> notStuck;
    for (int i = 0; i < (int)s.size(); i++) {
        bool repeat = true; // assume appear repeatedly
        for (int j = 1; j < k && i + j <= (int)s.size(); j++) { // null terminator '\0'
            if (s[i + j] != s[i]) {
                repeat = false;
                break;
            }
        }
        if (repeat) { // candidates: possibly stuck
            i += k - 1;
        } else {
            notStuck.emplace(s[i]);
        }
    }
    string res;
    unordered_set<char> out; // for output only once
    for (int i = 0; i < (int)s.size(); i++) {
        res += s[i];
        if (notStuck.find(s[i]) == notStuck.end()) { // stuck
            if (out.find(s[i]) == out.end()) { // not output yet
                cout << s[i];
                out.emplace(s[i]);
            }
            i += k - 1;
        }
    }
    cout << "\n" << res << "\n";

    return 0;
}
// @pintia code=end
