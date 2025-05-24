/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 17:21:19
 *	modified:	2023-03-28 21:38:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805485033603072 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1020 Tree Traversals
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805485033603072
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val, id;
};

vector<int> post, in;
vector<Node> level;

void preTra(int postR, int inL, int inH, int id) {
    // pre-order traversal for level order
    if (inL > inH) return;
    level.emplace_back(Node{post[postR], id});
    int inR = find(in.begin(), in.end(), post[postR]) - in.begin();
    preTra(postR - (inH - inR) - 1, inL, inR - 1, 2 * id); // right subtree size: inH - inR
    preTra(postR - 1, inR + 1, inH, 2 * id + 1);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    post.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    preTra(n - 1, 0, n - 1, 1);
    // level order traversal by sorting with index
    sort(level.begin(), level.end(), [](Node a, Node b) {
        return a.id < b.id;
    });
    for (int i = 0; i < n; i++) {
        cout << level[i].val;
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
