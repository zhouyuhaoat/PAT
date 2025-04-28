/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 16:55:06
 *	modified:	2024-05-17 16:59:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1729419732192542722 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1178 File Path
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542722
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    string root;
    cin >> n >> root;
    getchar();
    unordered_map<string, string> parent;
    unordered_map<int, string> level; // last node in each level
    parent[root] = "", level[0] = root;
    for (int i = 1; i < n; i++) {
        string s;
        getline(cin, s);
        int space = 0;
        while (isspace(s[space])) {
            space++;
        }
        s = s.substr(space);
        parent[s] = level[space - 1], level[space] = s;
        // the parent of current node is the last node in the previous level
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        string s;
        cin >> s;
        if (parent.find(s) == parent.end()) { // no parent
            cout << "Error: " << s << " is not found.\n";
        } else {
            string res;
            while (s != root) { // before the root: from bottom to top
                res = "->" + s + res;
                s = parent[s];
            }
            cout << root << res << "\n"; // include the root
        }
    }

    return 0;
}
// @pintia code=end
