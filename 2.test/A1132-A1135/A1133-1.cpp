/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 11:53:38
 *	modified:	2023-04-03 12:03:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805346776760320 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1133 Splitting A Linked List
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805346776760320
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

    int head, n, k;
    cin >> head >> n >> k;
    unordered_map<int, node> nodes;
    for (int i = 0; i < n; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr] = {data, next};
    }
    vector<int> ans, a2, a3;
    for (int p = head; p != -1; p = nodes[p].next) {
        if (nodes[p].data < 0) {
            ans.emplace_back(p);
        } else if (nodes[p].data <= k) {
            a2.emplace_back(p);
        } else {
            a3.emplace_back(p);
        }
    }
    ans.insert(ans.end(), a2.begin(), a2.end());
    ans.insert(ans.end(), a3.begin(), a3.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << setfill('0') << setw(5) << ans[i] << " " << nodes[ans[i]].data << " ";
        if (i < (int)ans.size() - 1) {
            cout << setfill('0') << setw(5) << ans[i + 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
