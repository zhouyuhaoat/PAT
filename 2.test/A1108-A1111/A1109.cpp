/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:10:27
 *	modified:	2023-04-02 22:27:58
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805360043343872 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1109 Group Photo
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360043343872
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct peo {
    string id;
    int h;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<peo> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].h;
    }
    sort(p.begin(), p.end(), [](peo a, peo b) -> bool {
        if (a.h != b.h) {
            return a.h > b.h;
        } else {
            return a.id < b.id;
        }
    });
    int rc = n / k, lrc = n - (k - 1) * rc; // row, last row
    for (int i = -1; i < k - 1; i++) {
        queue<string> q; // first to the left
        stack<string> s; // first to the right
        int t = (i == -1 ? 0 : lrc + i * rc); // start index
        for (int j = t; j < lrc + (i + 1) * rc; j++) {
            if ((j - t) % 2 == 0) {
                q.emplace(p[j].id);
            } else {
                s.emplace(p[j].id);
            }
        }
        vector<string> row;
        while (!s.empty()) {
            row.emplace_back(s.top());
            s.pop();
        }
        while (!q.empty()) {
            row.emplace_back(q.front());
            q.pop();
        }
        for (int i = 0; i < (int)row.size(); i++) {
            cout << row[i];
            i < (int)row.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end