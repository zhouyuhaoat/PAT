/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 22:53:15
 *	modified:	2023-04-14 23:18:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1729419732192542722 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1178 File Path
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542722
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

vector<int> par(1e4, -1); // parent of each node in the tree

void dfs(int v, vector<int> &ans) {
    if (v == 0) { // until the root
        ans.emplace_back(v); // before recursion
        return;
    }
    dfs(par[v], ans);
    ans.emplace_back(v); // after recursion: backtrack
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    getchar();
    stack<int> st;
    map<int, int> level;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int l = 0;
        while (isspace(s[l])) {
            l++;
        }
        int id = stoi(s.substr(l));
        level[id] = l;
        if (id == 0) {
            st.emplace(0), par[0] = 0;
            continue;
        }
        int p = st.top();
        while (l <= level[p]) {
            st.pop();
            p = st.top();
        }
        st.emplace(id), par[id] = p;
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        if (par[id] == -1) {
            cout << "Error: " << setfill('0') << setw(4) << id << " is not found." << "\n";
            continue;
        }
        vector<int> ans;
        dfs(id, ans); // find the path: from bottom to top
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << setfill('0') << setw(4) << ans[i];
            i < (int)ans.size() - 1 ? cout << "->" : cout << "\n";
        }
    }
    return 0;
}
// @pintia code=end