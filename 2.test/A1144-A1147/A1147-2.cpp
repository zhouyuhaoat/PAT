/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 15:22:47
 *	modified:	2023-04-04 15:56:06
 *	item:		Programming Ability Test
 *	site:		Yuting
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

vector<int> t, post;

void dfsMax(int r, int n, bool& flag) {
    // check if it is a max heap, and get postorder traversal
    if (r >= n) {
        return;
    }
    if (2 * r + 1 < n && t[r] < t[2 * r + 1]) { // left child
        flag = false;
    }
    if (2 * r + 2 < n && t[r] < t[2 * r + 2]) { // right child
        flag = false;
    }
    dfsMax(2 * r + 1, n, flag);
    dfsMax(2 * r + 2, n, flag);
    post.emplace_back(t[r]);
}

void dfsMin(int r, int n, bool& flag) {
    // check if it is a min heap, and get postorder traversal
    if (r >= n) {
        return;
    }
    if (2 * r + 1 < n && t[r] > t[2 * r + 1]) { // left child
        flag = false;
    }
    if (2 * r + 2 < n && t[r] > t[2 * r + 2]) { // right child
        flag = false;
    }
    dfsMin(2 * r + 1, n, flag);
    dfsMin(2 * r + 2, n, flag);
    post.emplace_back(t[r]);
}

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    t.resize(n);
    for (int q = 0; q < m; q++) {
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        bool isMaxHeap = true, isMinHeap = true; // suppose it is a max heap, or a min heap
        if (t[0] > t[1]) { // possibly be a max heap, can not be a min heap
            dfsMax(0, n, isMaxHeap);
            if (isMaxHeap) {
                cout << "Max Heap\n";
            }
        } else { // possibly be a min heap, can not be a max heap
            dfsMin(0, n, isMinHeap);
            if (isMinHeap) {
                cout << "Min Heap\n";
            }
        }
        if (!(isMinHeap && isMaxHeap)) {
            cout << "Not Heap\n";
        }
        for (int i = 0; i < n; i++) {
            cout << post[i];
            i < n - 1 ? cout << " " : cout << "\n";
        }
        post.clear();
    }

    return 0;
}
// @pintia code=end
