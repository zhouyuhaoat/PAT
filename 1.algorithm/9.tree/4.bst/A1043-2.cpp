/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 18:52:44
 *	modified:	2023-03-29 19:15:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805440976633856 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1043 Is It a Binary Search Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805440976633856
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

bool isMirror = false;
vector<int> pre, post;

void posttra(int r, int e) {
    if (r > e) return;
    int i = r + 1, j = e;
    if (!isMirror) { // normal
        while (i <= e && pre[i] < pre[r]) { // left subtree
            ++i;
        }
        while (j > r && pre[j] >= pre[r]) { // right subtree
            --j;
        }
    } else { // mirror
        while (i <= e && pre[i] >= pre[r]) { // left subtree
            ++i;
        }
        while (j > r && pre[j] < pre[r]) { // right subtree
            --j;
        }
    }
    if (i - j != 1) return; // not a BST
    posttra(r + 1, j);
    posttra(i, e);
    post.emplace_back(pre[r]);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    posttra(0, n - 1);
    if ((int)post.size() != n) { // possible mirror
        isMirror = true;
        post.clear();
        posttra(0, n - 1);
    }
    if ((int)post.size() == n) { // a BST or mirror
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << post[i];
            i < n - 1 ? cout << " " : cout << "\n";
        }
    } else { // not a BST and mirror
        cout << "NO\n";
    }

    return 0;
}
// @pintia code=end