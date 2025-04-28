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

vector<vector<int>> g(1e4);
vector<int> temp, res;

void dfs(int root, int target) {
    temp.emplace_back(root); // before recursion
    if (root == target) {
        res = temp;
        temp.pop_back(); // backtrack
        return;
    }
    for (int i = 0; i < (int)g[root].size(); i++) {
        dfs(g[root][i], target);
    }
    temp.pop_back(); // after recursion: backtrack
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    getchar();
    stack<int> stk;
    unordered_map<int, int> level;
    unordered_map<int, bool> exist;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int space = 0;
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
        while (space <= level[parent]) {
            stk.pop();
            parent = stk.top();
        }
        stk.emplace(id), g[parent].emplace_back(id);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        if (exist[id]) {
            dfs(0, id);
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
