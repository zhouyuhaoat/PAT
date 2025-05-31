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
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
    int x = 0, y = 0, dir = 0; // position, direction
    for (int i = 0; i < n; i++) {
        mat[x][y] = data[i]; // fill
        x += direction[dir][0], y += direction[dir][1];
        if (x < 0 || x >= row || y < 0 || y >= col || mat[x][y] != 0) { // out of bounds or already filled
            x -= direction[dir][0], y -= direction[dir][1]; // revert to last position
            dir = (dir + 1) % 4; // change direction
            x += direction[dir][0], y += direction[dir][1]; // move to next position
        }
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
