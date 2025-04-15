/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 23:15:25
 *	modified:	2023-03-26 23:46:00
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805480801550336 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1022 Digital Library
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805480801550336
*/

// @pintia code=start
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> splitWords(string s) { // split words by space manually
    vector<string> words;
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)s.size()) {
        if (!isspace(s[i])) {
            j = i;
            while (j < (int)s.size() && !isspace(s[j])) {
                j++;
            }
            words.emplace_back(s.substr(i, j - i));
            i = j;
        } else {
            i++;
        }
    }
    return words;
}

int main(int argc, char const *argv[]) {

    vector<unordered_map<string, set<string>>> m(6);
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string id;
        getline(cin, id);
        for (int j = 1; j < 6; j++) {
            string s;
            getline(cin, s);
            if (j != 3) {
                m[j][s].emplace(id);
            } else {
                vector<string> words = splitWords(s);
                for (string w : words) {
                    m[j][w].emplace(id);
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l;
        scanf("%d: ", &l);
        string s;
        getline(cin, s);
        cout << l << ": " << s << "\n";
        if (m[l][s].empty()) {
            cout << "Not Found\n";
        } else {
            for (auto it : m[l][s]) {
                cout << it << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
