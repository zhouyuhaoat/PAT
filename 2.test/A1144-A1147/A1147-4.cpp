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

vector<int> t, post;
bool isMaxHeap, isMinHeap;

void postTra(int r, int n) {
    if (r >= n) {
        return;
    }
    if (r != 0) {
        if (t[(r - 1) / 2] < t[r]) {
            isMaxHeap = false;
        }
        if (t[(r - 1) / 2] > t[r]) {
            isMinHeap = false;
        }
    }
    postTra(2 * r + 1, n);
    postTra(2 * r + 2, n);
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
        isMaxHeap = true, isMinHeap = true;
        postTra(0, n);
        if (isMaxHeap) {
            cout << "Max Heap\n";
        } else if (isMinHeap) {
            cout << "Min Heap\n";
        } else {
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
