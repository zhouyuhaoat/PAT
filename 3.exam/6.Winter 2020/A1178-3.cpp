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
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int u, vector<int>& res, unordered_map<int, int>& parents) {
    if (u == 0) { // until the root
        res.emplace_back(u);
        return;
    }
    dfs(parents[u], res, parents);
    res.emplace_back(u);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    getchar();
    stack<int> stk;
    unordered_map<int, int> level, parents; // parents of each node
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int space = s.find_first_not_of(' ');
        int id = stoi(s.substr(space));
        level[id] = space;
        if (stk.empty()) {
            stk.emplace(id), parents[id] = -1;
            continue;
        }
        int parent = stk.top();
        while (level[parent] >= space) {
            stk.pop();
            parent = stk.top();
        }
        stk.emplace(id), parents[id] = parent;
    }
    int k;
    cin >> k;
    while (k--) {
        int id;
        cin >> id;
        if (parents.find(id) == parents.end()) {
            cout << "Error: " << setfill('0') << setw(4) << id << " is not found." << "\n";
            continue;
        }
        vector<int> res;
        dfs(id, res, parents); // find the path: from bottom to top
        for (int i = 0; i < (int)res.size(); i++) {
            cout << setfill('0') << setw(4) << res[i];
            i < (int)res.size() - 1 ? cout << "->" : cout << "\n";
        }
    }
    return 0;
}
// @pintia code=end
