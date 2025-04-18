/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:37:03
 *	modified:	2023-04-02 22:16:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805359372255232 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1110 Complete Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805359372255232
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int lc, rc;
};

vector<bool> isRoot;
vector<node> t;

int getID(string s) {
    if (isdigit(s[0])) {
        isRoot[stoi(s)] = false;
        return stoi(s);
    } else {
        return -1;
    }
}

bool bfs(int r, int n, int& lastNode) {
    queue<int> q;
    q.emplace(r);
    while (n--) { // ensure all nodes are visited
        int f = q.front();
        q.pop();
        if (f == -1) { // if CBT, there is no empty node
            return false;
        }
        lastNode = f;
        q.emplace(t[f].lc);
        q.emplace(t[f].rc);
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n), isRoot.resize(n, true);
    for (int i = 0; i < n; i++) {
        string lc, rc;
        cin >> lc >> rc;
        t[i] = {getID(lc), getID(rc)};
    }
    int r = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin(), lastNode = -1;
    if (bfs(r, n, lastNode)) {
        cout << "YES " << lastNode << "\n";
    } else {
        cout << "NO " << r << "\n";
    }

    return 0;
}
// @pintia code=end
