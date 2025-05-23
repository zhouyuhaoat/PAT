/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:25:11
 *	modified:	2023-03-28 11:39:51
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    bool vis = false;
};

int getIntersectionNode(int head1, int head2, unordered_map<int, Node>& nodes) {
    for (int p = head1; p != -1; p = nodes[p].next) {
        nodes[p].vis = true;
    }
    for (int p = head2; p != -1; p = nodes[p].next) {
        if (nodes[p].vis) {
            return p;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {

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
