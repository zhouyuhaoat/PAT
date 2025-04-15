/*
 *	author:		zhouyuhao
 *	created:	2025-04-15 10:11:09
 *	modified:	2025-04-15 11:22:01
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805425780670464 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1052 Linked List Sorting
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805425780670464
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
    int addr, data, next;
};

int main(int argc, char const *argv[]) {

    int n, head;
    cin >> n >> head;
    if (head == -1) {
        cout << "0 -1\n";
        return 0;
    }
    unordered_map<int, node> nodes;
    for (int i = 0; i < n; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr] = {addr, data, next};
    }
    vector<int> addrs;
    for (int p = head; p != -1; p = nodes[p].next) {
        addrs.emplace_back(p);
    }
    head = -1; // Insertion Sort on Linked List
    for (int addr : addrs) {
        if (head == -1 || nodes[addr].data < nodes[head].data) {
            nodes[addr].next = head;
            head = addr;
        } else {
            int pre = head, cur = nodes[head].next;
            while (cur != -1 && nodes[cur].data < nodes[addr].data) {
                pre = cur;
                cur = nodes[cur].next;
            }
            nodes[addr].next = cur;
            nodes[pre].next = addr;
        }
    }
    cout << addrs.size() << " " << setfill('0') << setw(5) << (head == -1 ? -1 : head) << "\n";
    for (int p = head; p != -1; p = nodes[p].next) {
        cout << setfill('0') << setw(5) << p << " " << nodes[p].data << " ";
        if (nodes[p].next != -1) {
            cout << setfill('0') << setw(5) << nodes[p].next << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
