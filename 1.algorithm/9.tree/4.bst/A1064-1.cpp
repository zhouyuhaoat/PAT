/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 19:17:01
 *	modified:	2023-03-29 20:17:54
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
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> in, level;

void leveltra(int s, int e, int i) {
    if (s > e) return;
    int n = e - s + 1;
    int h = log(n + 1) / log(2);
    int l = n - pow(2, h) + 1;
    int r = s + pow(2, h - 1) - 1;
    r += min(l, (int)pow(2, h - 1));
    level[i] = in[r];
    leveltra(s, r - 1, 2 * i + 1);
    leveltra(r + 1, e, 2 * i + 2);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    // in order of BST: sorted
    sort(in.begin(), in.end());
    level.resize(n);
    leveltra(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
