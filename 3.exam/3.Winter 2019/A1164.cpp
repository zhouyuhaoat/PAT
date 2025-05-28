/*
 *	author:		zhouyuhao
 *	created:	2024-05-16 21:40:52
 *	modified:	2024-05-16 22:00:13
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1478635767601967104 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1164 Good in C
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635767601967104
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s) { // split by capital letters
    vector<string> words;
    for (int lo = 0, hi = 0; lo < (int)s.size() && hi < (int)s.size(); lo++) {
        if (isupper(s[lo])) {
            hi = lo;
            while (hi < (int)s.size() && isupper(s[hi])) {
                hi++;
            }
            words.emplace_back(s.substr(lo, hi - lo));
            lo = hi;
        }
    }
    return words;
}

int main(int argc, char const *argv[]) {

    vector<vector<string>> letter(26, vector<string>(7));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> letter[i][j];
        }
    }
    getchar();
    string s;
    getline(cin, s);
    vector<string> words = split(s);
    for (int i = 0; i < (int)words.size(); i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < (int)words[i].size(); k++) {
                cout << letter[words[i][k] - 'A'][j];
                k < (int)words[i].size() - 1 ? cout << " " : cout << "\n";
            }
        }
        if (i < (int)words.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
