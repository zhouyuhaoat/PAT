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
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> rea;
vector<int> pro;
unordered_map<int, set<vector<int>>> equ;
unordered_map<int, vector<int>> ans;

void dfs(int preL, int preH) { // bool -> void
    if (preL == preH) {
        for (auto proID : pro) {
            for (int i = 0; i < (int)ans[proID].size(); i++) {
                cout << setfill('0') << setw(2) << ans[proID][i];
                i < (int)ans[proID].size() - 1 ? cout << " + " : cout << " -> ";
            }
            cout << setfill('0') << setw(2) << proID << "\n";
        }
        exit(0); // exit the program
    }
    int proID = pro[preL];
    for (auto act : equ[proID]) {
        bool flag = true;
        for (auto reaID : act) {
            if (rea[reaID] == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        ans[proID] = act;
        for (auto reaID : act) {
            rea[reaID]--;
        }
        dfs(preL + 1, preH);
        for (auto reaID : act) {
            rea[reaID]++;
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
        if (rea[pro[i]] > 0) {
            equ[pro[i]].insert({pro[i]});
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
