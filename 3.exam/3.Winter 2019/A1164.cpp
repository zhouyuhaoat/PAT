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

int main(int argc, char const *argv[]) {

    vector<vector<string>> l(26, vector<string>(7));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> l[i][j];
        }
    }
    string t;
    getchar();
    getline(cin, t);
    vector<string> w; // split words with capital letters
    for (int i = 0; i < (int)t.size(); i++) {
        while (i < (int)t.size() && !isupper(t[i])) { // skip non-capital letters
            i++;
        }
        int j = i;
        while (j < (int)t.size() && isupper(t[j])) {
            j++;
        }
        if (i != j) { // if there is a word
            w.emplace_back(t.substr(i, j - i));
            i = j;
        }
    }
    for (int i = 0; i < (int)w.size(); i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < (int)w[i].size(); k++) {
                cout << l[w[i][k] - 'A'][j];
                k < (int)w[i].size() - 1 ? cout << " " : cout << "\n";
            }
        }
        if (i < (int)w.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end