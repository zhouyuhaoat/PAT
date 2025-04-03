/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 17:56:06
 *	modified:	2024-05-17 18:23:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=1729419732192542723 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1179 Chemical Equation
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542723
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, int> rea;
vector<int> pro;
map<int, set<vector<int>>> equ;
map<int, vector<int>> ans;

void dfs(int ps, int pe) { // bool -> void
    if (ps == pe) {
        for (auto it : pro) {
            for (int i = 0; i < (int)ans[it].size(); i++) {
                cout << setfill('0') << setw(2) << ans[it][i];
                i < (int)ans[it].size() - 1 ? cout << " + " : cout << " -> ";
            }
            cout << setfill('0') << setw(2) << it << "\n";
        }
        exit(0); // exit the program
    }
    int pi = pro[ps];
    for (auto it : equ[pi]) {
        bool isok = true;
        for (auto is : it) {
            if (rea[is] == 0) {
                isok = false;
                break;
            }
        }
        if (!isok) {
            continue;
        }
        ans[pi] = it;
        for (auto is : it) {
            rea[is]--;
        }
        dfs(ps + 1, pe);
        for (auto is : it) {
            rea[is]++;
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        rea[id]++;
    }
    int m;
    cin >> m;
    pro.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> pro[i];
        equ[pro[i]].insert({pro[i]});
        if (rea[pro[i]] == 0) {
            rea[pro[i]]++;
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int id;
        cin >> id;
        vector<int> temp;
        temp.emplace_back(id);
        string ch;
        while (cin >> ch) {
            cin >> id;
            if (ch == "+") {
                temp.emplace_back(id);
            } else {
                equ[id].emplace(temp);
                break;
            }
        }
    }
    dfs(0, m);

    return 0;
}
// @pintia code=end