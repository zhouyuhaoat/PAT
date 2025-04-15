/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:54:59
 *	modified:	2023-03-28 12:10:27
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805369774129152 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1097 Deduplication on a Linked List
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805369774129152
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
    int data, next;
};

int main(int argc, char const *argv[]) {

    int head, n;
    cin >> head >> n;
    unordered_map<int, node> nodes;
    for (int i = 0; i < n; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr] = {data, next};
    }
    vector<vector<int>> l(2);
    unordered_map<int, bool> vis;
    for (int p = head; p != -1; p = nodes[p].next) {
        int val = abs(nodes[p].data);
        if (!vis[val]) {
            l[0].emplace_back(p);
            vis[val] = true;
        } else {
            l[1].emplace_back(p);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (int)l[i].size(); j++) {
            cout << setfill('0') << setw(5) << l[i][j] << " " << nodes[l[i][j]].data << " ";
            if (j < (int)l[i].size() - 1) {
                cout << setfill('0') << setw(5) << l[i][j + 1] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
