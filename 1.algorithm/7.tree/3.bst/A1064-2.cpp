/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 20:38:11
 *	modified:	2023-03-29 20:38:50
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805407749357568 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1064 Complete Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805407749357568
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, idx = 0;
vector<int> in, cbt;

void inTra(int root) {
    if (root > n) return;
    inTra(2 * root);
    cbt[root] = in[idx++];
    inTra(2 * root + 1);
}

int main(int argc, char const *argv[]) {

    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    cbt.resize(n + 1);
    inTra(1); // 1-based index
    for (int i = 1; i <= n; i++) {
        cout << cbt[i];
        i < n ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
