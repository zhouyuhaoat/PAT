/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 23:05:51
 *	modified:	2023-04-14 23:12:48
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
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> g(1e4); // adjacency list of the tree
vector<int> temp, ans;

void dfs(int root, int target) {
    if (root == target) {
        ans = temp;
        return;
    }
    for (int i = 0; i < (int)g[root].size(); i++) {
        temp.emplace_back(g[root][i]); // before recursion
        dfs(g[root][i], target);
        temp.pop_back(); // after recursion: backtrack
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    getchar();
    stack<int> st; // for parent in the tree
    unordered_map<int, int> level; // indent by spaces
    unordered_map<int, bool> exist;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int l = 0; // level = indent
        while (isspace(s[l])) {
            l++;
        }
        int id = stoi(s.substr(l));
        level[id] = l, exist[id] = true;
        if (id == 0) {
            st.emplace(0);
            continue;
        }
        int p = st.top(); // parent
        while (l <= level[p]) { // the level of parent is smaller than current level
            st.pop();
            p = st.top();
        }
        st.emplace(id), g[p].emplace_back(id);
    }
    temp.emplace_back(0); // the root
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        if (exist[id]) {
            dfs(0, id); // find the path: from top to bottom
            for (int i = 0; i < (int)ans.size(); i++) {
                cout << setfill('0') << setw(4) << ans[i];
                i < (int)ans.size() - 1 ? cout << "->" : cout << "\n";
            }
        } else {
            cout << "Error: " << setfill('0') << setw(4) << id << " is not found.\n";
        }
    }

    return 0;
}
// @pintia code=end
