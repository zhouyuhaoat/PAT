/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 20:44:34
 *	modified:	2023-03-27 21:47:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805419468242944 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1056 Mice and Rice
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805419468242944
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, group; // group size
    cin >> n >> group;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    queue<int> q; // the initial playing order
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        q.emplace(id);
    }
    vector<int> rank(n);
    while (q.size() > 1) {
        int size = q.size(), g = size / group + (size % group != 0); // number of groups
        for (int i = 0; i < g; i++) {
            int fat = q.front();
            for (int j = 0; j < group && i * group + j < size; j++) { // current group
                if (weight[fat] < weight[q.front()]) {
                    fat = q.front();
                }
                rank[q.front()] = g + 1;
                q.pop();
            }
            q.emplace(fat); // next round
        }
    }
    rank[q.front()] = 1;
    for (int i = 0; i < n; i++) {
        cout << rank[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
