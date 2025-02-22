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

struct p {
    int x, y, z;
};

int m, n, l, t;
vector<vector<vector<int>>> b;
vector<vector<vector<bool>>> v;

int X[6] = {-1, 1, 0, 0, 0, 0};
int Y[6] = {0, 0, -1, 1, 0, 0};
int Z[6] = {0, 0, 0, 0, -1, 1};

bool islaw(int x, int y, int z) {
    if (x < 0 || x >= l || y < 0 || y >= m || z < 0 || z >= n) {
        return false;
    }
    if (b[x][y][z] == 0 || v[x][y][z]) {
        return false;
    }
    return true;
}

int bfs(int x, int y, int z) {
    queue<p> q;
    q.emplace(p{x, y, z});
    v[x][y][z] = true;
    int cnt = 0;
    while (!q.empty()) {
        p f = q.front();
        q.pop();
        ++cnt;
        for (int i = 0; i < 6; i++) {
            int vx = f.x + X[i], vy = f.y + Y[i], vz = f.z + Z[i];
            if (islaw(vx, vy, vz)) {
                q.emplace(p{vx, vy, vz});
                v[vx][vy][vz] = true;
            }
        }
    }
    if (cnt >= t) {
        return cnt;
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[]) {

    cin >> m >> n >> l >> t;
    b.resize(l), v.resize(l);
    for (int i = 0; i < l; i++) {
        b[i].resize(m), v[i].resize(m);
        for (int j = 0; j < m; j++) {
            b[i][j].resize(n), v[i][j].resize(n);
            for (int k = 0; k < n; k++) {
                cin >> b[i][j][k];
                v[i][j][k] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (b[i][j][k] == 1 && !v[i][j][k]) {
                    cnt += bfs(i, j, k);
                }
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end