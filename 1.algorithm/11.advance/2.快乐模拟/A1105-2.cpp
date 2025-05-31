/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 20:56:35
 *	modified:	2023-04-12 21:54:11
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805363117768704 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1105 Spiral Matrix
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805363117768704
*/

// @pintia code=start
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end(), greater<int>());
    int row = 0, col = 0;
    for (col = sqrt(n); col >= 1; col--) {
        if (n % col == 0) {
            row = n / col;
            break;
        }
    }
    vector<vector<int>> mat(row, vector<int>(col));
    int top = 0, bottom = row - 1, left = 0, right = col - 1, id = 0; // boundaries
    while (true) {
        for (int i = left; i <= right; i++) { // top row
            mat[top][i] = data[id++];
        }
        if (++top > bottom) break;
        for (int i = top; i <= bottom; i++) { // right column
            mat[i][right] = data[id++];
        }
        if (--right < left) break;
        for (int i = right; i >= left; i--) { // bottom row
            mat[bottom][i] = data[id++];
        }
        if (--bottom < top) break;
        for (int i = bottom; i >= top; i--) { // left column
            mat[i][left] = data[id++];
        }
        if (++left > right) break;
    }
    for (int i = 0; i < (int)mat.size(); i++) {
        for (int j = 0; j < (int)mat[i].size(); j++) {
            cout << mat[i][j];
            j < (int)mat[i].size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
