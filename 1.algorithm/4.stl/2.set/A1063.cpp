/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 22:10:10
 *	modified:	2023-03-26 22:17:22
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805409175420928 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1063 Set Similarity
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805409175420928
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<unordered_set<int>> sets(n + 1);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            sets[i + 1].emplace(v);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int set1, set2;
        cin >> set1 >> set2;
        int cnt = 0; // count the number of common elements
        for (int it : sets[set1]) {
            if (sets[set2].find(it) != sets[set2].end()) {
                cnt++;
            }
        }
        double rate = (double)cnt / (sets[set1].size() + sets[set2].size() - cnt) * 100; // similarity
        cout << fixed << setprecision(1) << rate << "%\n";
    }

    return 0;
}
// @pintia code=end
