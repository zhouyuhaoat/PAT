/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 18:45:52
 *	modified:	2023-04-02 18:54:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805355987451904 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1115 Counting Nodes in a Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805355987451904
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

struct node {
    int v;
    node *lc, *rc;
};

node *insert(node *r, int v) {
    if (!r) {
        r = new node{v, nullptr, nullptr};
        return r;
    }
    if (v <= r->v) {
        r->lc = insert(r->lc, v);
    } else {
        r->rc = insert(r->rc, v);
    }
    return r;
}

int maxL = -1;
unordered_map<int, int> cnt;
void dfs(node *r, int l) {
    if (!r) {
        return;
    }
    cnt[l]++;
    maxL = max(maxL, l);
    dfs(r->lc, l + 1);
    dfs(r->rc, l + 1);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node *r = nullptr;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        r = insert(r, v);
    }
    dfs(r, 1);
    cout << cnt[maxL] << " + " << cnt[maxL - 1] << " = " << cnt[maxL] + cnt[maxL - 1] << "\n";

    return 0;
}
// @pintia code=end
