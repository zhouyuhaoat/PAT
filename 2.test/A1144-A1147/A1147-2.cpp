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

vector<int> t, post;

void posttra(int r, int n) { // postorder traversal
    if (r >= n) {
        return;
    }
    posttra(2 * r + 1, n);
    posttra(2 * r + 2, n);
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
        if (is_heap(t.begin(), t.end())) {
            // is_heap() returns true if the range is a max heap
            cout << "Max Heap\n";
        } else if (is_heap(t.begin(), t.end(), greater<int>())) {
            // is_heap(greater<int>()) returns true if the range is a min heap
            cout << "Min Heap\n";
        } else {
            cout << "Not Heap\n";
        }
        posttra(0, n);
        for (int i = 0; i < n; i++) {
            cout << post[i];
            i < n - 1 ? cout << " " : cout << "\n";
        }
        post.clear();
    }

    return 0;
}
// @pintia code=end