/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 11:51:47
 *	modified:	2024-05-15 11:55:06
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805342821531648 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1147 Heaps
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805342821531648
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree, post;

void postTra(int root, int n) { // postorder traversal
    if (root >= n) return;
    postTra(2 * root + 1, n);
    postTra(2 * root + 2, n);
    post.emplace_back(tree[root]);
}

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    tree.resize(n);
    while (m--) {
        for (int i = 0; i < n; i++) {
            cin >> tree[i];
        }
        if (is_heap(tree.begin(), tree.end())) {
            // is_heap() returns true if the range is a max heap
            cout << "Max Heap\n";
        } else if (is_heap(tree.begin(), tree.end(), greater<int>())) {
            // is_heap(greater<int>()) returns true if the range is a min heap
            cout << "Min Heap\n";
        } else {
            cout << "Not Heap\n";
        }
        postTra(0, n);
        for (int i = 0; i < n; i++) {
            cout << post[i];
            i < n - 1 ? cout << " " : cout << "\n";
        }
        post.clear();
    }

    return 0;
}
// @pintia code=end
