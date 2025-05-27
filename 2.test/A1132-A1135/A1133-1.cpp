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

struct Node {
    int data, next;
};

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> res, list1, list2;
    for (int p = head; p != -1; p = nodes[p].next) {
        if (nodes[p].data < 0) {
            res.emplace_back(p);
        } else if (nodes[p].data <= k) {
            list1.emplace_back(p);
        } else {
            list2.emplace_back(p);
        }
    }
    res.insert(res.end(), list1.begin(), list1.end());
    res.insert(res.end(), list2.begin(), list2.end());
    for (int i = 0; i < (int)res.size(); i++) {
        cout << setfill('0') << setw(5) << res[i] << " " << nodes[res[i]].data << " ";
        if (i < (int)res.size() - 1) {
            cout << setfill('0') << setw(5) << res[i + 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
