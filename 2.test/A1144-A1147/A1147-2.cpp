/*
 *	author:		zhouyuhao
 *	created:	2025-04-20 11:51:47
 *	modified:	2025-04-20 11:55:06
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
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree, post;

bool isMaxHeap = true, isMinHeap = true; // assume it is a max heap, and a min heap
void isHeap(vector<int>& heap) {
    // judge heap property by parent-child relationship in one pass
    for (int i = 1; i < (int)heap.size(); i++) {
        if (heap[(i - 1) / 2] < heap[i]) { // parent < child
            isMaxHeap = false;
        }
        if (heap[(i - 1) / 2] > heap[i]) { // parent > child
            isMinHeap = false;
        }
    }
}

void postTra(int root, int n) {
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
        isMaxHeap = true, isMinHeap = true;
        isHeap(tree);
        if (isMaxHeap) {
            cout << "Max Heap\n";
        } else if (isMinHeap) {
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
