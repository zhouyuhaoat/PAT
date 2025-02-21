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
    vector<int> id(np);
    queue<int> q;
    for (int i = 0; i < np; i++) {
        cin >> id[i];
        q.emplace(id[i]);
    }
    vector<int> r(np);
    while (q.size() > 1) {
        vector<int> nowid;
        while (!q.empty()) {
            nowid.emplace_back(q.front());
            q.pop();
        }
        for (int i = 0; i <= (int)nowid.size() / ng; i++) {
            int maxw = -1, maxwid = -1;
            for (int j = 0; j < ng && i * ng + j < (int)nowid.size(); j++) {
                int idx = i * ng + j;
                if (w[nowid[idx]] > maxw) {
                    maxw = w[nowid[idx]];
                    maxwid = nowid[idx];
                }
            }
            if (maxwid != -1) {
                q.emplace(maxwid);
            }
        }
        for (auto it : nowid) {
            r[it] = q.size() + 1;
        }
    }
    r[q.front()] = 1;
    for (int i = 0; i < np; i++) {
        cout << r[i];
        if (i < np - 1) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end