/*
 *	author:		zhouyuhao
 *	created:	2025-04-19 11:53:38
 *	modified:	2025-04-19 12:03:45
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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

pair<int, int> list1 = {-1, -1}, list2 = list1, list3 = list1;

void update(pair<int, int>& cur, int p, unordered_map<int, Node>& nodes) {
    if (cur.first == -1) { // first node
        cur.first = cur.second = p;
    } else { // append
        nodes[cur.second].next = p;
        cur.second = p;
    }
}

int connect(unordered_map<int, Node>& nodes) {
    int head = -1, tail = -1;
    vector<pair<int, int>> lists = {list1, list2, list3};
    for (auto list : lists) {
        if (list.first != -1) { // not empty
            if (head == -1) { // first list
                head = list.first;
            } else { // tail != -1: not first list
                nodes[tail].next = list.first; // connect
            }
            tail = list.second;
        }
    }
    if (tail != -1) { // end
        nodes[tail].next = -1;
    }
    return head;
}

void print(int head, unordered_map<int, Node>& nodes) {
    for (int p = head; p != -1; p = nodes[p].next) {
        cout << setfill('0') << setw(5) << p << " " << nodes[p].data << " ";
        if (nodes[p].next != -1) {
            cout << setfill('0') << setw(5) << nodes[p].next << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    for (int p = head; p != -1; p = nodes[p].next) {
        if (nodes[p].data < 0) {
            update(list1, p, nodes);
        } else if (nodes[p].data <= k) {
            update(list2, p, nodes);
        } else {
            update(list3, p, nodes);
        }
    }
    head = connect(nodes);
    print(head, nodes);

    return 0;
}
// @pintia code=end
