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

struct node {
    int data, next;
};

void print(int head, unordered_map<int, node>& nodes) {
    for (int p = head; p != -1; p = nodes[p].next) {
        cout << setfill('0') << setw(5) << p << " " << nodes[p].data << " ";
        if (nodes[p].next != -1) {
            cout << setfill('0') << setw(5) << nodes[p].next << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

pair<int, int> l1 = {-1, -1}, l2 = l1, l3 = l1;
int connect(unordered_map<int, node>& nodes) {
    int head = -1, tail = -1;
    vector<pair<int, int>> lists = {l1, l2, l3};
    for (auto& lst : lists) {
        if (lst.first != -1) { // not empty
            if (head == -1) { // first list
                head = lst.first;
            }
            if (tail != -1) { // not first list
                nodes[tail].next = lst.first;
            }
            tail = lst.second;
        }
    }
    if (tail != -1) { // end
        nodes[tail].next = -1;
    }
    return head;
}

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    unordered_map<int, node> nodes;
    for (int i = 0; i < n; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr] = {data, next};
    }
    for (int p = head; p != -1; p = nodes[p].next) {
        int data = nodes[p].data;
        pair<int, int> *cur;
        if (data < 0) {
            cur = &l1;
        } else if (data <= k) {
            cur = &l2;
        } else {
            cur = &l3;
        }
        if (cur->first == -1) { // first node
            cur->first = cur->second = p;
        } else { // append
            nodes[cur->second].next = p;
            cur->second = p;
        }
    }
    head = connect(nodes);
    print(head, nodes);

    return 0;
}
// @pintia code=end
