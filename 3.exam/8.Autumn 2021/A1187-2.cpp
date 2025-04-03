/*
 *	author:		zhouyuhao
 *	created:	2025-04-03 17:46:13
 *	modified:	2025-04-03 17:55:09
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1187 Sorted Cartesian Tree
*/

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int key, pri;
    int lc = -1, rc = -1;
};

vector<node> t;
vector<int> level;

int insert(int root, int i) {
    if (root == -1) return i;
    if (t[i].key < t[root].key) {
        t[root].lc = insert(t[root].lc, i);
    } else {
        t[root].rc = insert(t[root].rc, i);
    }
    return root;
}

void leveltra(int root) {
    queue<int> q;
    q.emplace(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        level.emplace_back(cur);
        if (t[cur].lc != -1) q.emplace(t[cur].lc);
        if (t[cur].rc != -1) q.emplace(t[cur].rc);
    }
}

int main(int argc, char *argv[]) {

    int n;
    cin >> n;
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i].key >> t[i].pri;
    }
    sort(t.begin() + 1, t.end(), [](node a, node b) {
        return a.pri < b.pri;
    });
    int root = -1;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);
    }
    leveltra(root);
    for (int i = 0; i < (int)level.size(); i++) {
        cout << t[level[i]].key;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < (int)level.size(); i++) {
        cout << t[level[i]].pri;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}