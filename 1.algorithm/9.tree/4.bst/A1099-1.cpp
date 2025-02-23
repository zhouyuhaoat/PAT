/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 20:39:04
 *	modified:	2023-03-29 21:05:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805367987355648 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1099 Build A Binary Search Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805367987355648
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v;
    int lc, rc;
};

vector<node> t;
vector<int> in, ans;
int n, front = 0;

void intra(int r) {
    if (r == -1 || r >= n) return;
    intra(t[r].lc);
    t[r].v = in[front++];
    intra(t[r].rc);
}

void bfs(int r) {
    queue<int> q;
    q.emplace(r);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans.emplace_back(t[now].v);
        if (t[now].lc != -1) {
            q.emplace(t[now].lc);
        }
        if (t[now].rc != -1) {
            q.emplace(t[now].rc);
        }
    }
}

int main(int argc, char const *argv[]) {

    cin >> n;
    t.resize(n);
    vector<bool> isroot(n, true);
    for (int i = 0; i < n; i++) {
        cin >> t[i].lc >> t[i].rc;
        if (t[i].lc != -1) {
            isroot[t[i].lc] = false;
        }
        if (t[i].rc != -1) {
            isroot[t[i].rc] = false;
        }
    }
    int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    // in order of BST: sorted
    sort(in.begin(), in.end());
    intra(r);
    bfs(r);
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end