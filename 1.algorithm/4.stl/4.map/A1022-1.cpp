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

vector<string> split(string s) { // split manually by space
    vector<string> words;
    for (int lo = 0, hi = 0; lo < (int)s.size() && hi < (int)s.size(); lo++) {
        if (!isspace(s[lo])) {
            hi = lo;
            while (hi < (int)s.size() && !isspace(s[hi])) {
                hi++;
            }
            words.emplace_back(s.substr(lo, hi - lo));
            lo = hi;
        }
    }
    return words;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    getchar();
    vector<unordered_map<string, set<string>>> library(6); // type -> information -> id
    for (int i = 0; i < n; i++) {
        string id;
        getline(cin, id);
        // 1: title, 2: author, 3: key words, 4: publisher, 5: published year
        for (int type = 1; type < 6; type++) {
            string s;
            getline(cin, s);
            if (type != 3) {
                library[type][s].emplace(id);
            } else {
                vector<string> words = split(s);
                for (string word : words) {
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
        // 1: title, 2: author, 3: key word, 4: publisher, 5: published year
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
