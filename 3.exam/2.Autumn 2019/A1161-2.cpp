/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:33:11
 *	modified:	2023-04-05 20:57:47
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635524918910976 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1161 Merging Linked Lists
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635524918910976
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

int getSize(int head, unordered_map<int, Node>& nodes) {
    int size = 0;
    for (int p = head; p != -1; p = nodes[p].next) {
        size++;
    }
    return size;
}

int reverse(int head, unordered_map<int, Node>& nodes) {
    int pre = -1, cur = head;
    while (cur != -1) {
        int next = nodes[cur].next; // backup
        nodes[cur].next = pre; // reverse
        pre = cur, cur = next; // move forward
    }
    return pre;
}

int main(int argc, char const *argv[]) {

    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    if (getSize(head1, nodes) < getSize(head2, nodes)) {
        swap(head1, head2);
    }
    head2 = reverse(head2, nodes);
    for (int p1 = head1, p2 = head2, cnt = 1; p1 != -1 && p2 != -1; cnt++) { // merge
        if (cnt % 2 == 0) {
            int next1 = nodes[p1].next, next2 = nodes[p2].next;
            nodes[p1].next = p2, nodes[p2].next = next1;
            p1 = next1, p2 = next2;
        } else {
            p1 = nodes[p1].next;
        }
    }
    for (int p = head1; p != -1; p = nodes[p].next) {
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
