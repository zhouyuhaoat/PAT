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
vector<int> temp, res;

void dfs(int root, int target) { // root -> target
    if (root == target) {
        res = temp;
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
    stack<int> stk; // for parent in the tree
    unordered_map<int, int> level; // indent by spaces
    unordered_map<int, bool> exist;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int space = 0; // level = indent spaces
        while (isspace(s[space])) {
            space++;
        }
        int id = stoi(s.substr(space));
        level[id] = space, exist[id] = true;
        if (id == 0) {
            stk.emplace(0);
            continue;
        }
        int parent = stk.top();
        while (space <= level[parent]) { // the level of parent is smaller than current level
            stk.pop();
            parent = stk.top();
        }
        stk.emplace(id), g[parent].emplace_back(id);
    }
    temp.emplace_back(0); // the root
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        if (exist[id]) {
            dfs(0, id); // find the path: from top to bottom
            for (int i = 0; i < (int)res.size(); i++) {
                cout << setfill('0') << setw(4) << res[i];
                i < (int)res.size() - 1 ? cout << "->" : cout << "\n";
            }
        } else {
            cout << "Error: " << setfill('0') << setw(4) << id << " is not found.\n";
        }
    }

    return 0;
}
// @pintia code=end
