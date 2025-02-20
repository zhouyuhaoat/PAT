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
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    vector<map<string, set<string>>> m(6);
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
                // split words by space manually
                int p = 0, q = 0;
                while (p < (int)s.size() && q < (int)s.size()) {
                    if (!isspace(s[p])) {
                        q = p;
                        while (!isspace(s[q]) && q < (int)s.size()) {
                            ++q;
                        }
                        string w = s.substr(p, q - p);
                        m[j][w].emplace(id);
                        p = q;
                    } else {
                        ++p;
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l;
        int unused __attribute__((unused)) = 0;
        unused = scanf("%d: ", &l);
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