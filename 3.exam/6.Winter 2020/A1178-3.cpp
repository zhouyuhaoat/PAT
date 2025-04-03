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
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    string r;
    cin >> n >> r;
    getchar();
    map<string, string> p; // parent
    map<int, string> level; // last node in each level
    p[r] = "", level[0] = r;
    for (int i = 1; i < n; i++) {
        string s;
        getline(cin, s);
        int l = 0;
        while (isspace(s[l])) {
            l++;
        }
        s = s.substr(l);
        p[s] = level[l - 1], level[l] = s;
        // the parent of current node is the last node in the previous level
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        string s;
        cin >> s;
        if (p.find(s) == p.end()) { // no parent
            cout << "Error: " << s << " is not found.\n";
        } else {
            string ans;
            while (s != r) { // before the root: from bottom to top
                ans = "->" + s + ans;
                s = p[s];
            }
            cout << r << ans << "\n"; // include the root
        }
    }

    return 0;
}
// @pintia code=end