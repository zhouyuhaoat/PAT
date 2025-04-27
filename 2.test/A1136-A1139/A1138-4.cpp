/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 14:42:37
 *	modified:	2023-04-04 09:53:43
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805345078067200 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1138 Postorder Traversal
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345078067200
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> pre;
unordered_map<int, int> loc;

void postTra(int preR, int inL, int inH) {
    if (inL == inH) { // only one leaf node
        cout << pre[preR] << "\n";
        return;
    }
    int inR = loc[pre[preR]];
    if (inR - inL > 0) { // left subtree exists
        postTra(preR + 1, inL, inR - 1);
    } else if (inH - inR > 0) { // right subtree exists
        postTra(preR + (inR - inL) + 1, inR + 1, inH);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        loc[in] = i;
    }
    postTra(0, 0, n - 1);

    return 0;
}
// @pintia code=end
