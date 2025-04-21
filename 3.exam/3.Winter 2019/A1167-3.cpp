/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 23:24:58
 *	modified:	2023-04-05 23:55:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478636026017230848 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1167 Cartesian Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478636026017230848
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int v;
    node *lc, *rc;
};

vector<int> in;

node *create(int inL, int inH) {
    if (inL > inH) {
        return nullptr;
    }
    int inR = min_element(in.begin() + inL, in.begin() + inH + 1) - in.begin();
    node *root = new node{in[inR], nullptr, nullptr};
    root->lc = create(inL, inR - 1);
    root->rc = create(inR + 1, inH);
    return root;
}

vector<int> bfs(node *root) {
    vector<int> res;
    queue<node *> q;
    q.emplace(root);
    while (!q.empty()) {
        node *cur = q.front();
        q.pop();
        res.emplace_back(cur->v);
        if (cur->lc) {
            q.emplace(cur->lc);
        }
        if (cur->rc) {
            q.emplace(cur->rc);
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    node *root = create(0, n - 1);
    vector<int> res = bfs(root);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
