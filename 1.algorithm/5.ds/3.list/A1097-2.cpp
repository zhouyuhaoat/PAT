/*
 *	author:		zhouyuhao
 *	created:	2025-04-15 10:11:09
 *	modified:	2025-04-15 11:22:01
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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
#include <unordered_set>

using namespace std;

struct Node {
    int data, next;
};

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

    int head, n;
    cin >> head >> n;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    unordered_set<int> vis;
    pair<int, int> unq = {-1, -1}, dup = {-1, -1}; // unique, duplicate: {head, tail}
    for (int p = head; p != -1; p = nodes[p].next) {
        int val = abs(nodes[p].data);
        pair<int, int>& cur = (vis.count(val) == 0 ? unq : dup); // overwrite
        if (vis.count(val) == 0) {
            vis.emplace(val);
        }
        if (cur.first == -1) { // first node
            cur.first = cur.second = p;
        } else { // append
            cur.second = nodes[cur.second].next = p;
        }
    }
    nodes[unq.second].next = -1, nodes[dup.second].next = -1; // last node
    print(unq.first, nodes), print(dup.first, nodes);

    return 0;
}
// @pintia code=end
