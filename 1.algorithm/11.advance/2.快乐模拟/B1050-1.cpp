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
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end(), greater<int>());
    int row = 0, col = 0; // size of the matrix
    for (col = sqrt(n); col >= 1; col--) {
        if (n % col == 0) {
            row = n / col;
            break;
        }
    }
    vector<vector<int>> mat(row, vector<int>(col));
    int layer = 0, id = 0; // layer by layer
    while (id < n) { // fill the matrix in spiral order
        // x: row, y: column; (x, y): the beginning of the current layer
        int x = layer, y = layer; // top left corner
        for (int i = 0; i < col; i++) { // top row: left to right
            mat[x][y++] = data[id++];
        }
        if (id >= n) break;
        x++, y--; // top right corner
        for (int i = 0; i < row - 1; i++) { // right column: top to bottom
            mat[x++][y] = data[id++];
        }
        if (id >= n) break;
        x--, y--; // bottom right corner
        for (int i = 0; i < col - 1; i++) { // bottom row: right to left
            mat[x][y--] = data[id++];
        }
        if (id >= n) break;
        x--, y++; // bottom left corner
        for (int i = 0; i < row - 2; i++) { // left column: bottom to top
            mat[x--][y] = data[id++];
        }
        row -= 2, col -= 2, layer++; // next layer
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
