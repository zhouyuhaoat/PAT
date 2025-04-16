/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 22:52:29
 *	modified:	2023-03-28 23:22:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805365537882112 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1102 Invert a Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805365537882112
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int id;
    int lc, rc;
};

vector<node> d;
vector<int> level, in;

void invert(int r) { // recursion
    if (r == -1) return;
    invert(d[r].lc);
    invert(d[r].rc);
    swap(d[r].lc, d[r].rc);
}

void bfs(int r) {
    queue<int> s;
    s.emplace(r);
    while (!s.empty()) {
        int t = s.front();
        s.pop();
        level.emplace_back(t);
        if (d[t].lc != -1) s.emplace(d[t].lc);
        if (d[t].rc != -1) s.emplace(d[t].rc);
    }
}

void intra(int r) {
    if (d[r].lc != -1) intra(d[r].lc);
    in.emplace_back(r);
    if (d[r].rc != -1) intra(d[r].rc);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    d.resize(n);
    vector<bool> isroot(n, true);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (isdigit(c)) {
            d[i].lc = c - '0';
            isroot[d[i].lc] = false;
        } else {
            d[i].lc = -1;
        }
        cin >> c;
        if (isdigit(c)) {
            d[i].rc = c - '0';
            isroot[d[i].rc] = false;
        } else {
            d[i].rc = -1;
        }
    }
    int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
    invert(r);
    bfs(r);
    intra(r);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
