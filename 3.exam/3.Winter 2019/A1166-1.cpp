/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 23:05:58
 *	modified:	2023-04-05 23:24:39
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635919459287040 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1166 Summit
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635919459287040
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> r; // friendship relation

bool isFriend(vector<int>& area) {
    for (auto i : area) { // two loops for all pairs
        for (auto j : area) {
            if (i != j && !r[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int invite(int n, vector<int>& area, vector<bool>& inArea) {
    for (int i = 1; i <= n; i++) {
        if (!inArea[i]) {
            bool moreFri = true; // suppose it is a friend
            for (auto it : area) {
                if (!r[i][it]) {
                    moreFri = false;
                    break;
                }
            }
            if (moreFri) {
                return i;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    r.resize(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        r[a][b] = r[b][a] = true;
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int l;
        cin >> l;
        vector<int> area(l);
        vector<bool> inArea(n + 1);
        for (int i = 0; i < l; i++) {
            cin >> area[i];
            inArea[area[i]] = true;
        }
        if (!isFriend(area)) {
            cout << "Area " << q + 1 << " needs help.\n";
            continue;
        }
        int h = invite(n, area, inArea);
        if (h != 0) {
            cout << "Area " << q + 1 << " may invite more people, such as " << h << ".\n";
            continue;
        }
        cout << "Area " << q + 1 << " is OK.\n";
    }

    return 0;
}
// @pintia code=end
