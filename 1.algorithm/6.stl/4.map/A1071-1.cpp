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
#include <cctype>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> splitWords(string s) { // split words by alphanumeric
    vector<string> words;
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)s.size()) {
        if (isalnum(s[i])) {
            j = i;
            while (j < (int)s.size() && isalnum(s[j])) {
                j++;
            }
            words.push_back(s.substr(i, j - i));
            i = j;
        } else {
            i++;
        }
    }
    return words;
}

int main(int argc, char const *argv[]) {

    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    unordered_map<string, int> cnt;
    int maxcnt = -1;
    vector<string> words = splitWords(s);
    for (string w : words) {
        if (++cnt[w] > maxcnt) {
            maxcnt = cnt[w];
        }
    }
    for (auto it : cnt) {
        if (it.second == maxcnt) {
            cout << it.first << " " << it.second << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end
