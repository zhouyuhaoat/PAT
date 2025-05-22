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
        string word;
        for (char ch : s) {
            if (isalnum(ch)) {
                word += tolower(ch);
            } else {
                if (!word.empty()) {
                    cnt[word]++;
                    word.clear();
                }
            }
        }
        if (!word.empty()) { // the last word
            cnt[word]++;
        }
    }
    auto it = max_element(cnt.begin(), cnt.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    });
    cout << it->first << " " << it->second << "\n";

    return 0;
}
// @pintia code=end
