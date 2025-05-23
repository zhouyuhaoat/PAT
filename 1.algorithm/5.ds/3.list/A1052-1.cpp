/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:46:35
 *	modified:	2023-03-28 12:03:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805425780670464 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1052 Linked List Sorting
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805425780670464
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int addr, data, next;
};

int main(int argc, char const *argv[]) {

    int n, head;
    cin >> n >> head;
    if (head == -1) {
        cout << "0 -1\n";
        return 0;
    }
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr] = {addr, data, next};
    }
    vector<Node> list;
    for (int p = head; p != -1; p = nodes[p].next) {
        list.emplace_back(nodes[p]);
    }
    sort(list.begin(), list.end(), [](Node a, Node b) {
        return a.data < b.data;
    });
    cout << list.size() << " " << setfill('0') << setw(5) << list[0].addr << "\n";
    for (int i = 0; i < (int)list.size(); i++) {
        cout << setfill('0') << setw(5) << list[i].addr << " " << list[i].data << " ";
        if (i < (int)list.size() - 1) {
            cout << setfill('0') << setw(5) << list[i + 1].addr << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
