/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 15:47:21
 *	modified:	2024-05-15 15:58:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=1038429908921778176 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1149 Dangerous Goods Packaging
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038429908921778176
*/

// @pintia code=start
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    map<int, vector<int>> dan; // adjacency list
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dan[a].emplace_back(b);
        dan[b].emplace_back(a);
    }
    for (int q = 0; q < m; q++) {
        int k;
        cin >> k;
        vector<int> goods(k);
        map<int, bool> exist;
        for (int i = 0; i < k; i++) {
            cin >> goods[i];
            exist[goods[i]] = true;
        }
        bool issafe = true;
        for (int i = 0; i < k && issafe; i++) {
            // check if there is any dangerous goods in the adjacency list of each goods
            for (int j = 0; j < (int)dan[goods[i]].size() && issafe; j++) {
                if (exist[dan[goods[i]][j]]) {
                    issafe = false;
                }
            }
        }
        if (issafe) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end