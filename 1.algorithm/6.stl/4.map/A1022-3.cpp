/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 10:56:00
 *	modified:	2024-05-04 11:11:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

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
                // split words by stringstream & stream extraction operator
                istringstream ss(s);
                string w;
                while (ss >> w) {
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
