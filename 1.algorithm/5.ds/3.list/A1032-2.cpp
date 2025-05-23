/*
 *	author:		zhouyuhao
 *	created:	2025-04-15 11:45:35
 *	modified:	2025-04-15 15:23:35
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805460652113920 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1032 Sharing
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805460652113920
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int next;
};

int getIntersectionNode(int head1, int head2, unordered_map<int, Node>& nodes) {
    int p = head1, q = head2;
    // A: a + c; B: b + c => A: a + c -> B: b <=> B: b + c -> A: a
    // c = 0 => A: a; B: b => A: a -> B: b <=> B: b -> A: a
    // no intersection, all end with -1
    while (p != q) { // alternate traverse
        p = (p == -1) ? head2 : nodes[p].next;
        q = (q == -1) ? head1 : nodes[q].next;
    }
    return p;
}

int main(int argc, char *argv[]) {

    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        char data;
        cin >> addr >> data >> nodes[addr].next;
    }
    int share = getIntersectionNode(head1, head2, nodes);
    if (share != -1) {
        cout << setw(5) << setfill('0') << share << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
// @pintia code=end
