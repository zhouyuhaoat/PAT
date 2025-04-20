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

void isHeap(vector<int>& h) {
    for (int i = 1; i < (int)h.size(); i++) {
        if (h[(i - 1) / 2] < h[i]) { // parent < child
            isMaxHeap = false;
        }
        if (h[(i - 1) / 2] > h[i]) { // parent > child
            isMinHeap = false;
        }
    }
}

void postTra(int r, int n) {
    if (r >= n) {
        return;
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
        isMaxHeap = true, isMinHeap = true; // suppose it is a heap
        isHeap(t);
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
