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
#include <map>
#include <vector>

using namespace std;

vector<string> split(string s) { // split manually by alphanumeric
    vector<string> words;
    for (int lo = 0, hi = 0; lo < (int)s.size() && hi < (int)s.size(); lo++) {
        if (isalnum(s[lo])) {
            hi = lo;
            while (hi < (int)s.size() && isalnum(s[hi])) {
                hi++;
            }
            words.emplace_back(s.substr(lo, hi - lo));
            lo = hi;
        }
    }
    return words;
}

int main(int argc, char const *argv[]) {

    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    vector<string> words = split(s);
    map<string, int> cnt; // word -> count
    int maxCnt = -1;
    for (string word : words) {
        if (++cnt[word] > maxCnt) {
            maxCnt = cnt[word];
        }
    }
    for (auto [pattern, count] : cnt) { // lexicographically smallest one
        if (count == maxCnt) {
            cout << pattern << " " << count << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end
