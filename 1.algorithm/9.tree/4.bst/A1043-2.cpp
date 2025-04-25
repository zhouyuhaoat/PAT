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

bool mirror = false;
vector<int> pre, post;

void postTra(int preL, int preH) { // preL = preR
    if (preL > preH) return;
    int lo = preL + 1, hi = preH, root = pre[preL];
    if (!mirror) { // normal
        while (lo <= preH && pre[lo] < root) { // left subtree < root
            lo++;
        }
        while (hi > preL && pre[hi] >= root) { // right subtree >= root
            hi--;
        }
    } else { // mirror
        while (lo <= preH && pre[lo] >= root) { // left subtree >= root
            lo++;
        }
        while (hi > preL && pre[hi] < root) { // right subtree < root
            hi--;
        }
    }
    if (lo - hi != 1) return; // not a BST
    postTra(preL + 1, hi);
    postTra(lo, preH);
    post.emplace_back(pre[preL]);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    postTra(0, n - 1);
    if ((int)post.size() != n) { // possible mirror
        mirror = true;
        post.clear();
        postTra(0, n - 1);
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
