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
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> dangerous; // vector -> unordered_set
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dangerous[a].emplace(b);
        dangerous[b].emplace(a);
    }
    while (m--) {
        int k;
        cin >> k;
        unordered_set<int> goods;
        for (int i = 0; i < k; i++) {
            int good;
            cin >> good;
            goods.emplace(good);
        }
        bool safe = true;
        for (int good : goods) {
            if (dangerous.find(good) != dangerous.end()) { // dangerous
                for (int dangerousGood : dangerous[good]) { // adjacency list
                    if (goods.find(dangerousGood) != goods.end()) { // in goods
                        safe = false;
                        break;
                    }
                }
                if (!safe) {
                    break;
                }
            }
        }
        safe ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
