/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 17:27:00
 *	modified:	2024-05-04 17:41:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805375457411072 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1091 Acute Stroke
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805375457411072
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

struct Pixel {
    int x, y, z; // slice, row, column
};

// 6 directions: up, down, left, right, front, back
int dir[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
int m, n, l, t; // size (row, column) of matrix, slices of matrix, threshold
vector<vector<vector<int>>> pixel;
vector<vector<vector<bool>>> vis;

bool valid(Pixel p) {
    if (p.x < 0 || p.x >= l || p.y < 0 || p.y >= m || p.z < 0 || p.z >= n) {
        return false;
    }
    return true;
}

int bfs(int x, int y, int z) { // Flood Fill for connected components
    queue<Pixel> q;
    q.emplace(Pixel{x, y, z});
    vis[x][y][z] = true;
    int cnt = 0;
    while (!q.empty()) {
        Pixel u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            Pixel v = {u.x + dir[i][0], u.y + dir[i][1], u.z + dir[i][2]};
            if (valid(v) && pixel[v.x][v.y][v.z] == 1 && !vis[v.x][v.y][v.z]) {
                q.emplace(v);
                vis[v.x][v.y][v.z] = true;
            }
        }
    }
    return cnt >= t ? cnt : 0;
}

int main(int argc, char const *argv[]) {

    cin >> m >> n >> l >> t;
    pixel.resize(l), vis.resize(l);
    for (int i = 0; i < l; i++) {
        pixel[i].resize(m), vis[i].resize(m);
        for (int j = 0; j < m; j++) {
            pixel[i][j].resize(n), vis[i][j].resize(n);
            for (int k = 0; k < n; k++) {
                cin >> pixel[i][j][k];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (pixel[i][j][k] == 1 && !vis[i][j][k]) {
                    cnt += bfs(i, j, k);
                }
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
