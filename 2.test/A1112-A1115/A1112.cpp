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
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    string s;
    cin >> s;
    set<char> stucked, unstucked; // possible stucked keys, not stucked keys
    vector<char> ans;
    for (int i = 0; i < (int)s.size(); i++) {
        bool flag = true; // appear repeatedly
        for (int j = 1; j < k && i + j <= (int)s.size(); j++) {
            if (s[i + j] != s[i]) {
                flag = false;
                break;
            }
        }
        if (flag) { // candidates
            if (unstucked.find(s[i]) == unstucked.end()) {
                stucked.emplace(s[i]);
                ans.emplace_back(s[i]);
            }
            i += k - 1;
        } else {
            unstucked.emplace(s[i]);
        }
    }
    stucked.clear();
    for (auto it : ans) { // candidates
        // but also can be unstucked keys after it becomes candidates, so check again
        if (unstucked.find(it) == unstucked.end()) {
            if (stucked.find(it) == stucked.end()) { // output only once
                stucked.emplace(it);
                cout << it;
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < (int)s.size(); i++) {
        bool flag = true;
        for (int j = 1; j < k && i + j <= (int)s.size(); j++) {
            if (s[i + j] != s[i]) {
                flag = false;
                break;
            }
        }
        if (flag && unstucked.find(s[i]) == unstucked.end()) { // stucked keys
            cout << s[i];
            i += k - 1;
            continue;
        }
        cout << s[i];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end