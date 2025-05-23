/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:11:09
 *	modified:	2023-03-28 11:22:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805394512134144 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1074 Reversing Linked List
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805394512134144
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
    for (int i = 0; i + k <= (int)list.size(); i += k) {
        reverse(list.begin() + i, list.begin() + i + k);
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
