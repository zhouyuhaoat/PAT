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

vector<vector<bool>> relate; // friendship relation

bool isFriend(vector<int>& area) {
    for (int u : area) { // two loops for all pairs
        for (int v : area) {
            if (u != v && !relate[u][v]) {
                return false;
            }
        }
    }
    return true;
}

int invite(vector<int>& area, vector<bool>& inArea) {
    for (int u = 1; u < (int)inArea.size(); u++) {
        if (!inArea[u]) {
            bool more = true; // assume it is a friend
            for (int v : area) {
                if (!relate[u][v]) {
                    more = false;
                    break;
                }
            }
            if (more) {
                return u;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    relate.resize(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        relate[u][v] = relate[v][u] = true;
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
        int head = invite(area, inArea);
        if (head != 0) {
            cout << "Area " << q + 1 << " may invite more people, such as " << head << ".\n";
            continue;
        }
        cout << "Area " << q + 1 << " is OK.\n";
    }

    return 0;
}
// @pintia code=end
