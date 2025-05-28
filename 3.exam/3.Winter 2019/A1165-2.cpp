/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 22:49:25
 *	modified:	2023-04-05 23:05:37
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635841315209216 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1165 Block Reversing
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635841315209216
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

unordered_map<int, Node> nodes;
vector<pair<int, int>> lists;

void print(int head) {
    for (int p = head; p != -1; p = nodes[p].next) {
        cout << setfill('0') << setw(5) << p << " " << nodes[p].data << " ";
        if (nodes[p].next != -1) {
            cout << setfill('0') << setw(5) << nodes[p].next << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

int connect() {
    int head = -1, tail = -1;
    for (int i = lists.size() - 1; i >= 0; i--) {
        auto list = lists[i];
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

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    for (int p = head, cnt = 0; p != -1; p = nodes[p].next, cnt++) {
        if (cnt % k == 0) { // new list
            lists.emplace_back(p, p);
        } else { // update tail
            lists.back().second = p;
        }
    }
    head = connect();
    print(head);

    return 0;
}
// @pintia code=end
