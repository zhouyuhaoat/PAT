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
#include <map>
#include <set>
#include <vector>

using namespace std;

// chemical equation: reactants -> product
map<int, int> rea; // reactant -> amount
vector<int> pro; // product
map<int, set<vector<int>>> equ; // equation: product -> reactants
map<int, vector<int>> ans; // product -> reactant

bool dfs(int ps, int pe) { // whether all products [ps, pe) can be produced
    if (ps == pe) { // all products are produced
        return true;
    }
    int pi = pro[ps]; // current product
    for (auto it : equ[pi]) { // formulae for current product
        bool isok = true; // whether all reactants are available
        for (auto is : it) {
            if (rea[is] == 0) {
                isok = false;
                break;
            }
        }
        if (!isok) {
            continue; // next formula
        }
        ans[pi] = it;
        for (auto is : it) {
            rea[is]--; // recursion: consume the reactants
        }
        if (dfs(ps + 1, pe)) { // next product
            return true;
        }
        for (auto is : it) {
            rea[is]++; // backtrack: restore the reactants
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
        if (rea[pro[i]] > 0) {
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
    for (auto it : pro) {
        for (int i = 0; i < (int)ans[it].size(); i++) {
            cout << setfill('0') << setw(2) << ans[it][i];
            i < (int)ans[it].size() - 1 ? cout << " + " : cout << " -> ";
        }
        cout << setfill('0') << setw(2) << it << "\n";
    }

    return 0;
}
// @pintia code=end