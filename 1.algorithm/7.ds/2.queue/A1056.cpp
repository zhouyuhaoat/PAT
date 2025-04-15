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

    int np, ng;
    cin >> np >> ng;
    vector<int> w(np);
    for (int i = 0; i < np; i++) {
        cin >> w[i];
    }
    queue<int> q;
    for (int i = 0; i < np; i++) {
        int id;
        cin >> id;
        q.emplace(id);
    }
    vector<int> r(np);
    while (q.size() > 1) {
        int size = q.size(), g = size / ng + (size % ng != 0);
        for (int i = 0; i < g; i++) {
            int k = q.front();
            for (int j = 0; j < ng && i * ng + j < size; j++) {
                if (w[k] < w[q.front()]) {
                    k = q.front();
                }
                r[q.front()] = g + 1;
                q.pop();
            }
            q.emplace(k);
        }
    }
    r[q.front()] = 1;
    for (int i = 0; i < np; i++) {
        cout << r[i];
        i < np - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
