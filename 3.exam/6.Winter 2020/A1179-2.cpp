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

unordered_map<int, int> reactants;
vector<int> products;
unordered_map<int, set<vector<int>>> equations;
unordered_map<int, vector<int>> res;

void dfs(int preL, int preH) { // bool -> void
    if (preL == preH) {
        for (int product : products) {
            for (int i = 0; i < (int)res[product].size(); i++) {
                cout << setfill('0') << setw(2) << res[product][i];
                i < (int)res[product].size() - 1 ? cout << " + " : cout << " -> ";
            }
            cout << setfill('0') << setw(2) << product << "\n";
        }
        exit(0); // exit the program
    }
    int product = products[preL];
    for (auto equation : equations[product]) {
        bool flag = true;
        for (int reactant : equation) {
            if (reactants[reactant] == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        res[product] = equation;
        for (int reactant : equation) {
            reactants[reactant]--;
        }
        dfs(preL + 1, preH);
        for (int reactant : equation) {
            reactants[reactant]++;
        }
    }
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
        if (reactants[products[i]] > 0) {
            equations[products[i]].insert({products[i]});
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
                equations[id].emplace(temp);
                break;
            }
        }
    }
    dfs(0, m);

    return 0;
}
// @pintia code=end
