/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 22:17:40
 *	modified:	2023-04-14 22:17:43
 *	item:		Programming Ability Test
 *	site:		Shahu
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

// chemical equation: reactants -> product
unordered_map<int, int> rea; // reactant -> amount
vector<int> pro; // product
unordered_map<int, set<vector<int>>> equ; // equation: product -> reactants
unordered_map<int, vector<int>> ans; // product -> reactant

bool dfs(int proL, int proH) { // whether all products [proL, proH) can be produced
    if (proL == proH) { // all products are produced
        return true;
    }
    int proID = pro[proL]; // current product
    for (auto act : equ[proID]) { // formulae for current product
        bool flag = true; // whether all reactants are available
        for (auto reaID : act) {
            if (rea[reaID] == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue; // next formula
        }
        ans[proID] = act;
        for (auto reaID : act) {
            rea[reaID]--; // recursion: consume the reactants
        }
        if (dfs(proL + 1, proH)) { // next product
            return true;
        }
        for (auto reaID : act) {
            rea[reaID]++; // backtrack: restore the reactants
        }
    }
    return false;
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
        if (rea[pro[i]] > 0) { // if product is a reactant
            equ[pro[i]].insert({pro[i]}); // default product is itself
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
                temp.emplace_back(id); // reactants
            } else { // "->"
                equ[id].emplace(temp); // product -> reactants
                break;
            }
        }
    }
    dfs(0, m);
    for (auto proID : pro) {
        for (int i = 0; i < (int)ans[proID].size(); i++) {
            cout << setfill('0') << setw(2) << ans[proID][i];
            i < (int)ans[proID].size() - 1 ? cout << " + " : cout << " -> ";
        }
        cout << setfill('0') << setw(2) << proID << "\n";
    }

    return 0;
}
// @pintia code=end
