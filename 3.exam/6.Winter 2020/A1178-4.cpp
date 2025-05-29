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
    string root; // int -> string
    cin >> n >> root;
    getchar();
    unordered_map<string, string> parents;
    unordered_map<int, string> last; // last node in each level
    parents[root] = "", last[0] = root;
    for (int i = 1; i < n; i++) {
        string s;
        getline(cin, s);
        int space = s.find_first_not_of(' ');
        s = s.substr(space);
        parents[s] = last[space - 1], last[space] = s;
        // the parent of current node is the last node in the previous level
    }
    int k;
    cin >> k;
    while (k--) {
        string s;
        cin >> s;
        if (parents.find(s) == parents.end()) { // no parent
            cout << "Error: " << s << " is not found.\n";
        } else {
            string res;
            while (s != root) { // until the root: from bottom to top
                res = "->" + s + res;
                s = parents[s];
            }
            cout << root << res << "\n";
        }
    }

    return 0;
}
// @pintia code=end
