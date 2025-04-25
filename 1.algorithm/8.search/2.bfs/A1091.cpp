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

struct pixel {
    int x, y, z; // slice, row, column
};

int m, n, l, t; // size (row, column) of matrix, slices of matrix, threshold
vector<vector<vector<int>>> MRI; // Magnetic Resonance Imaging
vector<vector<vector<bool>>> vis;

// 6 directions: up, down, left, right, front, back
int X[6] = {-1, 1, 0, 0, 0, 0};
int Y[6] = {0, 0, -1, 1, 0, 0};
int Z[6] = {0, 0, 0, 0, -1, 1};

bool valid(pixel p) {
    if (p.x < 0 || p.x >= l || p.y < 0 || p.y >= m || p.z < 0 || p.z >= n) {
        return false;
    }
    return true;
}

int bfs(int x, int y, int z) { // Flood Fill
    queue<pixel> q;
    q.emplace(pixel{x, y, z});
    vis[x][y][z] = true;
    int cnt = 0;
    while (!q.empty()) {
        pixel u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            pixel v = {u.x + X[i], u.y + Y[i], u.z + Z[i]};
            if (valid(v) && MRI[v.x][v.y][v.z] == 1 && !vis[v.x][v.y][v.z]) {
                q.emplace(v);
                vis[v.x][v.y][v.z] = true;
            }
        }
    }
    return cnt >= t ? cnt : 0;
}

int main(int argc, char const *argv[]) {

    cin >> m >> n >> l >> t;
    MRI.resize(l), vis.resize(l);
    for (int i = 0; i < l; i++) {
        MRI[i].resize(m), vis[i].resize(m);
        for (int j = 0; j < m; j++) {
            MRI[i][j].resize(n), vis[i][j].resize(n);
            for (int k = 0; k < n; k++) {
                cin >> MRI[i][j][k];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (MRI[i][j][k] == 1 && !vis[i][j][k]) {
                    cnt += bfs(i, j, k);
                }
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
