/*
 *	author:		zhouyuhao
 *	created:	2025-04-15 10:11:09
 *	modified:	2025-04-15 11:22:01
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805296180871168 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1025 反转链表
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805296180871168
*/

// @pintia code=start
#include <algorithm>
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
    vector<int> list;
    for (int p = head; p != -1; p = nodes[p].next) {
        list.emplace_back(p);
    }
    for (int i = 0; i < (int)list.size() / k; i++) { // k: group size
        reverse(list.begin() + i * k, list.begin() + (i + 1) * k);
    }
    for (int i = 0; i < (int)list.size(); i++) {
        cout << setfill('0') << setw(5) << list[i] << " " << nodes[list[i]].data << " ";
        if (i < (int)list.size() - 1) {
            cout << setfill('0') << setw(5) << list[i + 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
