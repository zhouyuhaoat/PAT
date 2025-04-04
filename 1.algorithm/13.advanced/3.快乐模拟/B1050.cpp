/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 20:56:35
 *	modified:	2023-04-12 21:54:11
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805260223102976 pid=994805275146436608 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1050 螺旋矩阵
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805275146436608
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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end(), greater<int>());
    int col = 0, row = 0; // size of the matrix
    for (int i = sqrt(n); i >= 1; i--) { // find the largest factor
        if (n % i == 0) {
            col = i, row = n / i;
            break;
        }
    }
    vector<vector<int>> ans(row, vector<int>(col));
    int layer = 0, id = 0;
    while (id < n) {
        int x = layer, y = layer; // top left corner
        for (int i = 0; i < col; i++) { // top row, left to right
            ans[x][y++] = d[id++];
        }
        if (id >= n) break;
        y--, x++; // top right corner
        for (int i = 0; i < row - 1; i++) { // right column, top to bottom
            ans[x++][y] = d[id++];
        }
        if (id >= n) break;
        x--, y--; // bottom right corner
        for (int i = 0; i < col - 1; i++) { // bottom row, right to left
            ans[x][y--] = d[id++];
        }
        if (id >= n) break;
        y++, x--; // bottom left corner
        for (int i = 0; i < row - 2; i++) { // left column, bottom to top
            ans[x--][y] = d[id++];
        }
        row -= 2, col -= 2, layer++; // move to the next layer
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        for (int j = 0; j < (int)ans[i].size(); j++) {
            cout << ans[i][j];
            j < (int)ans[i].size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end