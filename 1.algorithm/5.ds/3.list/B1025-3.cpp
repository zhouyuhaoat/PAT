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
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data, next;
};

pair<int, int> reverse(int head, int tail, unordered_map<int, Node>& nodes) {
    int pre = -1, cur = head;
    while (pre != tail) {
        int next = nodes[cur].next; // backup
        nodes[cur].next = pre; // reverse
        pre = cur, cur = next; // move forward
    }
    return {tail, head};
}

int reverseKGroup(int head, int k, unordered_map<int, Node>& nodes) {
    int dummy = head, *cur = &dummy;
    // cur: a pointer to the head of the current group, or the next of the previous group
    while (*cur != -1) {
        int head = *cur, tail = *cur;
        for (int i = 1; i < k; ++i) {
            tail = nodes[tail].next;
            if (tail == -1) {
                return dummy;
            }
        }
        int next = nodes[tail].next;
        // cur = head, ..., tail, next
        tie(head, tail) = reverse(head, tail, nodes);
        *cur = head, nodes[tail].next = next; // connect
        cur = &nodes[tail].next; // move forward
    }
    return dummy;
}

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    unordered_map<int, Node> nodes;
    for (int i = 1; i <= n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    head = reverseKGroup(head, k, nodes);
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
