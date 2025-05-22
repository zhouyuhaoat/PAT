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

    int n;
    cin >> n;
    getchar();
    vector<unordered_map<string, set<string>>> library(6);
    for (int i = 0; i < n; i++) {
        string id;
        getline(cin, id);
        for (int type = 1; type < 6; type++) {
            string s;
            getline(cin, s);
            if (type != 3) {
                library[type][s].emplace(id);
            } else {
                istringstream ss(s); // split by stringstream & stream extraction operator
                string word;
                while (ss >> word) {
                    library[type][word].emplace(id);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        scanf("%d: ", &type);
        string s;
        getline(cin, s);
        cout << type << ": " << s << "\n";
        if (library[type][s].empty()) {
            cout << "Not Found\n";
        } else {
            for (string id : library[type][s]) {
                cout << id << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
