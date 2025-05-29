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
unordered_map<int, int> reactants; // reactant -> amount
vector<int> products;
unordered_map<int, set<vector<int>>> equations; // equation: product -> reactants
unordered_map<int, vector<int>> res; // products -> reactants

bool dfs(int proL, int proH) { // whether all products [proL, proH) can be produced
    if (proL == proH) { // all products are produced
        return true;
    }
    int product = products[proL]; // current product
    for (auto equation : equations[product]) { // formulae for current product
        bool flag = true; // whether all reactants are available
        for (int reactant : equation) {
            if (reactants[reactant] == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue; // next formula
        }
        res[product] = equation;
        for (int reactant : equation) {
            reactants[reactant]--; // recursion: consume the reactants
        }
        if (dfs(proL + 1, proH)) { // next product
            return true;
        }
        for (int reactant : equation) {
            reactants[reactant]++; // backtrack: restore the reactants
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
        reactants[id]++;
    }
    int m;
    cin >> m;
    products.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> products[i];
        if (reactants[products[i]] > 0) { // if product is a reactant
            equations[products[i]].insert({products[i]}); // default product is itself
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
                equations[id].emplace(temp); // product -> reactants
                break;
            }
        }
    }
    dfs(0, m);
    for (int product : products) {
        for (int i = 0; i < (int)res[product].size(); i++) {
            cout << setfill('0') << setw(2) << res[product][i];
            i < (int)res[product].size() - 1 ? cout << " + " : cout << " -> ";
        }
        cout << setfill('0') << setw(2) << product << "\n";
    }

    return 0;
}
// @pintia code=end
